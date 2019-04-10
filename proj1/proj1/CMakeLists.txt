cmake_minimum_required(VERSION 3.10)
project(proj1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp vector3.cpp)
target_link_libraries(${PROJECT_NAME} opencv_core opencv_highgui opencv_imgcodecs)

