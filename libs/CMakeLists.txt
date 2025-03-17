# libs/CMakeLists.txt
# 设置库文件的头文件
set(LIB_HEADERS
    lib.h
)
# 设置库文件源代码
set(LIB_SOURCES
    lib.cpp
)

# 创建静态库
add_library(mylib STATIC ${LIB_SOURCES}) # STATIC 可改为 SHARED 生成动态库

# 设置头文件路径
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})