cmake_minimum_required(VERSION 3.12)
project(waterSim)


set(CMAKE_CXX_STANDARD 14)
set(INC_DIR include)
set(LINK_DIR lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")


include_directories(${INC_DIR})
link_directories(${LINK_DIR})


add_executable(waterSim
        .idea/codeStyles/Project.xml
        .idea/misc.xml
        .idea/modules.xml
        .idea/opengl.iml
        .idea/vcs.xml
        .idea/workspace.xml
        bin/opengl.exe
        cmake-build-debug/CMakeCache.txt
        lib/glfw3.dll
        lib/libassimp.dll
        lib/libassimp.dll.a
        lib/libglfw3.a
        lib/libglfw3dll.a
        res/pic/alps_bk.tga
        res/pic/alps_dn.tga
        res/pic/alps_ft.tga
        res/pic/alps_lf.tga
        res/pic/alps_rt.tga
        res/pic/alps_up.tga
        res/pic/awesomeface.png
        res/pic/back.jpg
        res/pic/bottom.jpg
        res/pic/container.jpg
        res/pic/container2.png
        res/pic/container2_specular.png
        res/pic/front.jpg
        res/pic/lcy.jpg
        res/pic/left.jpg
        res/pic/right.jpg
        res/pic/top.jpg
        res/pic/wall.jpg
        res/shaderCode/33shader.frag
        res/shaderCode/33shader.vert
        res/shaderCode/fboShader.frag
        res/shaderCode/fboShader.vert
        res/shaderCode/light_shader.frag
        res/shaderCode/light_shader.vert
        res/shaderCode/model_shader.frag
        res/shaderCode/model_shader.vert
        res/shaderCode/skybox_shader.frag
        res/shaderCode/skybox_shader.vert
        res/shaderCode/water_shader.frag
        res/shaderCode/water_shader.vert
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
        src/RenderEngine/displayManager.cpp
        src/RenderEngine/displayManager.h
        src/RenderEngine/gameEngine.cpp
        src/RenderEngine/gameEngine.h
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
        .gitignore
        CMakeLists.txt
        README.md src/Skybox/skyboxRenderer.cpp src/Skybox/skyboxRenderer.h src/Camera/dirLight.cpp src/Camera/dirLight.h)

target_link_libraries(waterSim
        opengl32
        glfw3
        assimp)