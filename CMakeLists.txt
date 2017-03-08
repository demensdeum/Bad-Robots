cmake_minimum_required(VERSION 3.5)
project(FlameSteelZombieNight)

set(FSEGT_PROJECT_NAME BadRobots)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})
set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${FSEGT_PROJECT_NAME})

include_directories(.)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -I ../FlameSteelFramework")

file(GLOB_RECURSE SOURCE_FILES
    "../FlameSteelFramework/FlameSteelEngine/*.h"
    "../FlameSteelFramework/FlameSteelEngine/*.cpp"
    "../FlameSteelFramework/FlameSteelEngineGameToolkit/*.h"
    "../FlameSteelFramework/FlameSteelEngineGameToolkit/*.cpp"
    "BadRobots/*.h"
    "BadRobots/*.cpp"    
)

add_executable(${FSEGT_PROJECT_NAME} ${SOURCE_FILES})

find_package (SDL REQUIRED)
include_directories (${SDL_INCLUDE_DIR})
target_link_libraries(${FSEGT_PROJECT_NAME} ${SDL_LIBRARY})

find_package (SDL_image REQUIRED)
include_directories (${SDL_IMAGE_INCLUDE_DIR})
target_link_libraries(${FSEGT_PROJECT_NAME} ${SDL_IMAGE_LIBRARY})

find_package (SDL_ttf REQUIRED)
include_directories (${SDL_TTF_INCLUDE_DIR})
target_link_libraries(${FSEGT_PROJECT_NAME} ${SDL_TTF_LIBRARY})