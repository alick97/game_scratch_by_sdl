cmake_minimum_required(VERSION 3.17)

project(Game VERSION 1.0)

set(CMAKE_DEBUG_POSTFIX debug)

# specify the C++ standard.
add_library(game_compiler_flags INTERFACE)
target_compile_features(game_compiler_flags INTERFACE cxx_std_17)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# control where the static and shared libraries are built so that on windows.
# we don't need to tinker with the path to run the executable.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# For Third party cmake model.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


# configure a header file to pass some of the CMake settings
# to the source code.
configure_file(GameConfig.h.in GameConfig.h)


# Third party.
# SDL2 lib.
find_package(SDL2 REQUIRED)

# Find and link SDL2_image
find_package(SDL2_image REQUIRED)

# tinyxml2 lib.
add_subdirectory(external/tingxml2)
include_directories(${tingxml2_INCLUDE_DIRS})

# add the executable.
file(GLOB SOURCE_FILES src/*.cpp)
add_executable(Game ${SOURCE_FILES})
set_target_properties(Game PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_link_libraries(Game PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} tinyxml2 game_compiler_flags) 
target_include_directories(Game PUBLIC
                           ${SDL2_INCLUDE_DIRS}
                           ${SDL2_IMAGE_INCLUDE_DIRS})
