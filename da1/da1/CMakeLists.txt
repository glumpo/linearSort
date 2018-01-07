cmake_minimum_required(VERSION 2.8)

project(da1)

file(GLOB SRC . *.cpp)
file(GLOB HDR . *.h)

add_executable(${PROJECT_NAME} ${SRC} ${HDR})
