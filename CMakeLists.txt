cmake_minimum_required(VERSION 3.12)
project(opengl)

set(CMAKE_BUILD_TYPE Release)
set(INC_DIR "D:\\devSupport\\opengl\\include")
set(LINK_DIR lib)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_compile_options(-lassimp)

include_directories(${INC_DIR})

link_directories(${LINK_DIR})


add_executable(opengl
        src/Shader/shader.h
        src/tool/stb_image.h
        src/tool/stb_image.cpp
        src/Camera/camera.h
        src/Entities/mesh.h
        src/Entities/model.h
        src/glad.c
        src/main.cpp
        src/water/waterTile.h
        src/water/waterTile.cpp
        src/water/waterShader.h
        src/water/waterShader.cpp
        src/Shader/shader.cpp
        src/tool/tool.h
        src/water/waterRenderer.cpp
        src/water/waterRenderer.h
        src/RenderEngine/displayManager.cpp
        src/RenderEngine/displayManager.h
        src/Camera/camera.cpp
        src/RenderEngine/loader.cpp
        src/RenderEngine/loader.h
        src/Entities/object.cpp
        src/Entities/object.h
        src/water/waterFbo.cpp
        src/water/waterFbo.h src/RenderEngine/gameEngine.cpp src/RenderEngine/gameEngine.h src/RenderEngine/mainRenderer.cpp src/RenderEngine/mainRenderer.h src/Camera/light.cpp src/Camera/light.h src/Entities/model.cpp src/Entities/mesh.cpp)

target_link_libraries(opengl
        opengl32
        glfw3
        assimp)