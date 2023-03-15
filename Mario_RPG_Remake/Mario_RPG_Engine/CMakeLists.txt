set(HEADER_FILES
    src/MarioRPGUtils.h
    src/MarioRPGApp.h
    src/GameWindow.h
    src/GLFWCode/GLFWimplementation.h
)

set(SOURCE_FILES
    src/MarioRPGApp.cpp
    src/GameWindow.cpp
    src/GLFWCode/GLFWimplementation.cpp
)

add_library(Mario_RPG_Engine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)

target_precompile_headers(Mario_RPG_Engine PRIVATE src/pch.h)

target_link_libraries(Mario_RPG_Engine glfw)

add_definitions(-DMARIORPG_LIB)
add_definitions(-DMARIO_RPG_ENGINE_GLFW)