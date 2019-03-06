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
        src/shader/shader.h
        src/tool/stb_image.h
        src/tool/stb_image.cpp
        src/camera/camera.h
        src/mesh.h
        src/model.h
        src/glad.c
        src/main.cpp
        src/water/waterTile.h
        src/water/waterTile.cpp
        src/water/waterShader.h
        src/water/waterShader.cpp
        src/shader/shader.cpp
        src/tool/tool.h
        src/water/waterRenderer.cpp
        src/water/waterRenderer.h
        src/renderEngine/displayManager.cpp
        src/renderEngine/displayManager.h
        src/camera/camera.cpp
        src/renderEngine/loader.cpp
        src/renderEngine/loader.h
        src/renderEngine/object.cpp
        src/renderEngine/object.h
        src/water/waterFrameBuffer.cpp
        src/water/waterFrameBuffer.h)

target_link_libraries(opengl
        opengl32
        glfw3
        assimp)