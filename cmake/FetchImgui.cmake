# Fetch imgui source code from Github

include(FetchContent)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG        c6e0284ac58b3f205c95365478888f7b53b077e2 # v1.89.9
  SOURCE_DIR     imgui
)

FetchContent_MakeAvailable(imgui)

add_library(imgui STATIC
  imgui/imgui.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_tables.cpp
  imgui/imgui_widgets.cpp
  imgui/backends/imgui_impl_sdl2.cpp
  imgui/backends/imgui_impl_sdlrenderer2.cpp
)

target_include_directories(imgui PUBLIC
  ${CMAKE_CURRENT_BINARY_DIR}/imgui
  ${CMAKE_CURRENT_BINARY_DIR}/imgui/backends
)
