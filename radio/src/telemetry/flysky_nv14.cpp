/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "opentx.h"
#include "flysky_nv14.h"
#include "flysky_ibus.h"
#include "dataconstants.h"



#define FLYSKY_FIXED_RX_VOLTAGE (uint8_t)(FLYSKY_SENSOR_RX_VOLTAGE + (uint8_t)0xA0)

#define MIN_SNR 8
#define MAX_SNR 45

#define FIXED_PRECISION 15
#define FIXED(val) (val << FIXED_PRECISION)
#define DECIMAL(val) (val >> FIXED_PRECISION)
#define R_DIV_G_MUL_10_Q15 UINT64_C(9591506)
#define INV_LOG2_E_Q1DOT31 UINT64_C(0x58b90bfc) // Inverse log base 2 of e

struct FlyskyNv14Sensor {
  const uint16_t id;
  const uint8_t subId;
  const char * name;
  const TelemetryUnit unit;
  const uint8_t precision;
  const uint8_t offset;
  const uint8_t bytes;
  const bool issigned;
};

union nv14SensorData {
  uint8_t UINT8;
  uint16_t UINT16;
  int16_t INT16;
  uint32_t UINT32;
};

FlyskyNv14Sensor defaultNv14Sensor = {0, 0, "UNKNOWN", UNIT_RAW, 0, 0, 2, false};

const FlyskyNv14Sensor Nv14Sensor[]=
{
    {FLYSKY_FIXED_RX_VOLTAGE,  0, STR_SENSOR_A1,          UNIT_VOLTS,         2, 0, 2, false},
    {FLYSKY_SENSOR_RX_SIGNAL,  0, STR_SENSOR_RX_SIGNAL,   UNIT_RAW,           0, 0, 2, false},
    {FLYSKY_SENSOR_RX_RSSI,    0, STR_SENSOR_RSSI,        UNIT_DB,            0, 0, 2, true,},
    {FLYSKY_SENSOR_RX_NOISE,   0, STR_SENSOR_RX_NOISE,    UNIT_DB,            0, 0, 2, true},
    {FLYSKY_SENSOR_RX_SNR,     0, STR_SENSOR_RX_SNR,      UNIT_DB,            0, 0, 2, false},
    {FLYSKY_SENSOR_RX_SNR,     1, STR_SENSOR_RX_QUALITY,  UNIT_PERCENT,       0, 0, 2, false},
    {FLYSKY_SENSOR_TEMP,       0, STR_SENSOR_TEMP1,       UNIT_CELSIUS,       1, 0, 2, true},
    {FLYSKY_SENSOR_EXT_VOLTAGE,0, STR_SENSOR_A3,          UNIT_VOLTS,         2, 0, 2, false},
    {FLYSKY_SENSOR_MOTO_RPM,   0, STR_SENSOR_RPM,         UNIT_RPMS,          0, 0, 2, false},
    {FLYSKY_SENSOR_PRESURRE,   0, STR_SENSOR_PRES,        UNIT_RAW,           1, 0, 2, false},
    {FLYSKY_SENSOR_PRESURRE,   1, STR_SENSOR_ALT,         UNIT_METERS,        2, 0, 2, true},
    {FLYSKY_SENSOR_GPS,        1, STR_SENSOR_SATELLITES,  UNIT_RAW,           0, 0, 1, false},
    {FLYSKY_SENSOR_GPS,        2, STR_SENSOR_GPS,         UNIT_GPS_LATITUDE,  0, 1, 4, true},
    {FLYSKY_SENSOR_GPS,        3, STR_SENSOR_GPS,         UNIT_GPS_LONGITUDE, 0, 5, 4, true},
    {FLYSKY_SENSOR_GPS,        4, STR_SENSOR_ALT,         UNIT_METERS,        0, 8, 2, true},
    {FLYSKY_SENSOR_GPS,        5, STR_SENSOR_GSPD,        UNIT_KMH,           1, 10, 2, false},
    {FLYSKY_SENSOR_GPS,        6, STR_SENSOR_HDG,         UNIT_DEGREE,        3, 12, 2, false},
    {FLYSKY_SENSOR_SYNC,       0, "Sync",                 UNIT_RAW,           0, 0,  2, false},
    defaultNv14Sensor
};


extern uint32_t NV14internalModuleFwVersion;

extern int32_t getALT(uint32_t value);


signed short CalculateAltitude(unsigned int pressure)
{
  int32_t alt = getALT(pressure|(700 >> 19));
  return alt;
}

const FlyskyNv14Sensor* getFlyskyNv14Sensor(uint16_t id, uint8_t subId)
{
  for(const FlyskyNv14Sensor* sensor = Nv14Sensor; sensor->id; sensor++ ){
    if (sensor->id == id && sensor->subId == subId) {
      return sensor;
    }
  }
  return &defaultNv14Sensor;
}

void flySkyNv14SetDefault(int index, uint8_t id, uint8_t subId, uint8_t instance)
{
    TelemetrySensor & telemetrySensor = g_model.telemetrySensors[index];
    telemetrySensor.id = id;
    telemetrySensor.subId = subId;
    telemetrySensor.instance = instance;
    const FlyskyNv14Sensor* sensor = getFlyskyNv14Sensor(id, subId);
    telemetrySensor.init(sensor->name, sensor->unit, sensor->precision);
    if (sensor->unit == UNIT_RPMS) {
      telemetrySensor.custom.ratio = 1;
      telemetrySensor.custom.offset = 1;
    }    
    storageDirty(EE_MODEL);
}

int32_t GetSensorValueFlySkyNv14(const FlyskyNv14Sensor* sensor, const uint8_t * data){
  int32_t value = 0;
  const nv14SensorData* sensorData = reinterpret_cast<const nv14SensorData*>(data + sensor->offset);
  if(sensor->bytes == 1) value = sensorData->UINT8;
  else if(sensor->bytes == 2) value = sensor->issigned ? sensorData->INT16 : sensorData->UINT16;
  else if(sensor->bytes == 4) value = sensorData->UINT32;

  if(sensor->id == FLYSKY_SENSOR_RX_RSSI) {
    if(value < -200) value = -200;
#if defined(PCBNV14)
    if (!g_model.rssiAlarms.flysky_telemetry)
#endif
    {
      value += 200;
      value /= 2;
    }
    telemetryData.rssi.set(value);
  }
  if(sensor->id == FLYSKY_SENSOR_PRESURRE && sensor->subId != 0){
    value = CalculateAltitude(value);
  }
  return value;
}

// Module pulse synchronization
#define SAFE_SYNC_LAG          800 /* us */
#define SYNC_UPDATE_TIMEOUT    200 /* *10ms */
#define AFHDS2_SYNC_SAMPLES         8
#define AFHDS2_NEGATIVE_SYNC_LIMIT  (AFHDS2_PERIOD - SAFE_SYNC_LAG)

int16_t syncAfhds2min=0;
int16_t syncAfhds2max=0;
unsigned currentSyncIndex;

void flySkyNv14Sync(int16_t delayValue) {
  if(delayValue > AFHDS2_NEGATIVE_SYNC_LIMIT) {
     delayValue -= AFHDS2_PERIOD;
  }
  if (currentSyncIndex == 0) {
    syncAfhds2min = AFHDS2_PERIOD;
    syncAfhds2max = -SAFE_SYNC_LAG;
  }

  if(delayValue > syncAfhds2max) {
    syncAfhds2max = delayValue;
  }
  if(delayValue < syncAfhds2min) {
    syncAfhds2min = delayValue;
  }
  if (currentSyncIndex++ == AFHDS2_SYNC_SAMPLES) {
    currentSyncIndex = 0;
    //check against to late delivered frames up to 800us, some frames still in range
    if (syncAfhds2min < 0 && syncAfhds2max < SAFE_SYNC_LAG) {
      getModuleSyncStatus(INTERNAL_MODULE).update(AFHDS2_PERIOD, (syncAfhds2min-100)+SAFE_SYNC_LAG);
    }
    else if(syncAfhds2max > SAFE_SYNC_LAG + 100) { // > 900us
      if (syncAfhds2min > 100) { //never sync if last registred value is below 100us - we are to close to perfect time
        getModuleSyncStatus(INTERNAL_MODULE).update(AFHDS2_PERIOD, (syncAfhds2min-100)+SAFE_SYNC_LAG);
      }
      else if (syncAfhds2min < 0) {
        getModuleSyncStatus(INTERNAL_MODULE).update(AFHDS2_PERIOD, (syncAfhds2max-900)+SAFE_SYNC_LAG);
      }
    }
  }
}
void flySkyNv14ProcessTelemetryPacket(const uint8_t * ptr, uint8_t size)
{ 
  uint8_t sensorID = ptr[0];
  uint8_t instnace = ptr[1];
  int sensorCount = 0;
  if(sensorID != FLYSKY_SENSOR_SYNC) sensorCount++;
  
  //native telemetry for 1.1.2
  if(NV14internalModuleFwVersion >= 0x010102) {
    if(sensorID == FLYSKY_SENSOR_SYNC) flySkyNv14Sync((int16_t)(ptr[3] << 8 | ptr[2]));
    uint8_t frameType = 0xAA;
    if (size > 4) {
      frameType = 0xAC;
    } else if(size != 4) {
      return;
    } 
    processFlySkySensor(ptr, frameType);
  }
  else {
    if(sensorID == FLYSKY_SENSOR_RX_VOLTAGE) sensorID = FLYSKY_FIXED_RX_VOLTAGE;
    for (const FlyskyNv14Sensor* sensor = Nv14Sensor; sensor->id; sensor++) {
      if (sensor->id == sensorID) {
        int32_t value = GetSensorValueFlySkyNv14(sensor, ptr + 2);
        setTelemetryValue(PROTOCOL_TELEMETRY_FLYSKY_NV14, sensor->id, sensor->subId, instnace, value, sensor->unit, sensor->precision);
        if(sensor->id == FLYSKY_SENSOR_SYNC) flySkyNv14Sync(value);
      }
    }
  }
  if (sensorCount) {
    telemetryStreaming = TELEMETRY_TIMEOUT10ms;
  }
}

