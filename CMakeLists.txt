# 指定CMake的最低版本
cmake_minimum_required(VERSION 3.0) 

# 指定项目名称
project(HelloCMake)

# 设置变量
set(SRC_LIST main.cpp utils.cpp)

# 添加可执行文件
# add_executable(hello main.cpp utils.cpp)
add_executable(hello ${SRC_LIST})

# 为可执行文件添加头文件目录
target_include_directories(hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})