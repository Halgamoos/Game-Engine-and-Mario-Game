cmake_minimum_required(VERSION 3.24)

project(Mario_RPG_Remake)

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
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(Mario_RPG_Engine)
add_subdirectory(Mario_RPG_Game)

# Mario_RPG_Game here VS_STARTUP_PROJECT NOT subdirectory
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Mario_RPG_Game)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)