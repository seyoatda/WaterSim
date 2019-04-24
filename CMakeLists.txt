cmake_minimum_required(VERSION 3.12)
project(waterSim)


set(CMAKE_CXX_STANDARD 14)
set(INC_DIR include)
set(LINK_DIR lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")


include_directories(${INC_DIR})
link_directories(${LINK_DIR})


add_executable(waterSim
        src/Camera/camera.cpp
        src/Camera/camera.h
        src/Camera/light.cpp
        src/Camera/light.h
        src/Entities/mesh.cpp
        src/Entities/mesh.h
        src/Entities/model.cpp
        src/Entities/model.h
        src/Entities/object.cpp
        src/Entities/object.h
        src/RenderEngine/windowManager.cpp
        src/RenderEngine/windowManager.h
        src/RenderEngine/renderEngine.cpp
        src/RenderEngine/renderEngine.h
        src/RenderEngine/loader.cpp
        src/RenderEngine/loader.h
        src/RenderEngine/mainRenderer.cpp
        src/RenderEngine/mainRenderer.h
        src/Shader/shader.cpp
        src/Shader/shader.h
        src/tool/stb_image.cpp
        src/tool/stb_image.h
        src/tool/tool.h
        src/water/waterFbo.cpp
        src/water/waterFbo.h
        src/water/waterRenderer.cpp
        src/water/waterRenderer.h
        src/water/waterShader.cpp
        src/water/waterShader.h
        src/water/waterTile.cpp
        src/water/waterTile.h
        src/glad.c
        src/main.cpp
        src/Skybox/skyboxRenderer.cpp
        src/Skybox/skyboxRenderer.h
        src/Camera/dirLight.cpp
        src/Camera/dirLight.h
        src/tool/drawer.cpp
        src/tool/drawer.h src/Shader/basicShader.cpp src/Shader/basicShader.h)

target_link_libraries(waterSim
        opengl32
        glfw3
        assimp)