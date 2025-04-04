# 根目录的CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(my_project)

# MakeLists.txt 自动指定 toolchainFile（不通过命令行）
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "E:/ThirdPartyPackages/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译器选项
if (MSVC)
    add_compile_options(/W4 /WX)  # MSVC编译器的警告级别和错误处理
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)  # GCC/Clang编译器的警告级别和错误处理
endif()

# 添加src和libs子目录
add_subdirectory(src)
add_subdirectory(libs)
