cmake_minimum_required(VERSION 3.25)
project(Space)

set(CMAKE_CXX_STANDARD 17)

add_executable(Space src/main.cpp src/Ship.cpp headers/Ship.h src/Controller.cpp src/View.cpp src/GameLogic.cpp headers/View.h headers/GameLogic.h headers/Controller.h src/View.cpp headers/View.h src/Ship.cpp headers/Ship.h src/GameLogic.cpp headers/GameLogic.h src/Controller.cpp headers/Controller.h src/Asteroid.cpp headers/Asteroid.h src/Bullet.cpp headers/Bullet.h)

# Set the path to the directory containing FindSFML.cmake
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# Find SFML package
find_package(SFML REQUIRED system window graphics)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Space ${SFML_LIBRARIES})
endif ()

# Copy assets to build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy DLLs to build directory (for Windows)
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


