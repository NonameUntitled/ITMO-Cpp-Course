cmake_minimum_required(VERSION 3.10.2)

project(Homework4)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2")

set(PATH_TO_SOURCES srcs/Rational)

enable_testing()

file(GLOB CPPS "srcs/*.cpp")

include_directories(${PATH_TO_SOURCES}/lib_rational)

include_directories(${PATH_TO_SOURCES}/rational_poly)

add_subdirectory(${PATH_TO_SOURCES}/lib_rational)

add_subdirectory(${PATH_TO_SOURCES}/rational_poly)

add_subdirectory(srcs/tests)

add_executable(${PROJECT_NAME} ${CPPS})

target_link_libraries(${PROJECT_NAME} lib_rational rational_poly)
