cmake_minimum_required(VERSION 3.31)
project(proj)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_executable(${PROJECT_NAME} 
  src/proj.cc
  src/game.cc
)

add_custom_target(run
  COMMAND ${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

# find_package(raylib)
add_subdirectory(lib/raylib)
target_link_libraries(${PROJECT_NAME} raylib)

target_include_directories(${PROJECT_NAME} PRIVATE src/engine)