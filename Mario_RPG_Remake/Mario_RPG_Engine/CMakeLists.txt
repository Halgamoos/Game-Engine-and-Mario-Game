set(HEADER_FILES
    src/MarioRPGUtils.h
    src/MarioRPGApp.h
    src/GameWindow.h
    src/GLFWCode/GLFWimplementation.h
    src/Renderer.h
    src/ImplRenderer.h
    src/OpenGLCode/OpenGLRenderer.h
    src/RendererTypes.h
    src/Shader.h
    src/ImplShader.h
    src/OpenGLCode/OpenGLShader.h
    src/Image.h
    src/ImplImage.h
    src/OpenGLCode/OpenGLImage.h
    src/Unit.h
    src/MarioRPGEvents.h
    src/MarioKeys.h
)

set(SOURCE_FILES
    src/MarioRPGApp.cpp
    src/GameWindow.cpp
    src/GLFWCode/GLFWimplementation.cpp
    src/Renderer.cpp
    src/OpenGLCode/OpenGLRenderer.cpp
    src/Shader.cpp
    src/OpenGLCode/OpenGLShader.cpp
    src/Image.cpp
    src/OpenGLCode/OpenGLImage.cpp
    src/Unit.cpp
    src/MarioRPGEvents.cpp
)

add_library(Mario_RPG_Engine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)

target_precompile_headers(Mario_RPG_Engine PRIVATE src/pch.h)

target_link_libraries(Mario_RPG_Engine glfw glad stbi)

add_definitions(-DMARIORPG_LIB)
add_definitions(-DMARIORPG_WINDOWS)
add_definitions(-DMARIO_RPG_ENGINE_GLFW)
add_definitions(-DMARIO_OPENGL)
add_definitions(-DMARIO_DEBUG=2)