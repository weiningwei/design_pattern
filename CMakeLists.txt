cmake_minimum_required(VERSION 3.10)

project(design_pattern)
set(CMAKE_BUILD_TYPE Release)

include_directories("src/**/**.h")
# 01-simple_factory
add_executable(simple_factory ./src/01_simple_factory/operation.cpp)
# 02-strategy
add_executable(strategy ./src/02_strategy/cash_compute.cpp)
# 03-decorator
add_executable(decorator ./src/03_decorator/finery.cpp)
# 04-proxy
add_executable(proxy ./src/04_proxy/pursuit.cpp)
# 05-factory_method
add_executable(factory_method ./src/05_factory_method/leifeng.cpp)
# 06-prototype
add_executable(prototype ./src/06_prototype/resume.cpp)
# 07-template_method
add_executable(template_method ./src/07_template_method/test_paper.cpp)

# target_link_libraries(main ${OpenCV_LIBS})
# cmake -G "MinGW Makefiles" ..