cmake_minimum_required(VERSION 3.24)

project(mario_rpg_remake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
    add_definitions(-DMARIORPG_WINDOWS)
elseif(APPLE)
    add_definitions(-DMARIORPG_MACOS)
else()
    add_definitions(-DMARIORPG_LINUX)
endif()

add_subdirectory(glfw)
add_subdirectory(Mario_RPG_Engine)
add_subdirectory(Mario_RPG_Game)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT mario_rpg_game)