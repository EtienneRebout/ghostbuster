cmake_minimum_required(VERSION 3.9)
project(ghostbuster)

set(CMAKE_CXX_STANDARD 11)

add_executable(ghostbuster
        ai.cpp
        ai.h
        Constantes.h
        Fantome.cpp
        Fantome.h
        main.cpp
        Pacman.cpp
        Pacman.h
        Personnage.cpp
        Personnage.h
        sdlclg.cpp
        sdlclg.h Sources/PacNode.cpp Sources/PacNode.h Sources/GhostNode.cpp Sources/GhostNode.h Sources/AleaNode.cpp Sources/AleaNode.h Sources/Node.cpp Sources/Node.h)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})