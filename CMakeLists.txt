cmake_minimum_required(VERSION 3.10)

project(design_pattern)
set(CMAKE_BUILD_TYPE Release)

# 01-simple_factory
add_executable(simple_factory ./src/01_simple_factory/operation.cpp)
# target_link_libraries(main ${OpenCV_LIBS})

# cmake -G "MinGW Makefiles" ..