# src/CMakeLists.txt
# 设置源文件
set(SOURCES
    main.cpp
    utils.cpp
    helper.cpp
)
# 生成可执行文件
add_executable(my_project ${SOURCES})   
# 设置头文件路径
target_include_directories(my_project PUBLIC ${PROJECT_SOURCE_DIR}/include)
# 设置链接库路径
# target_link_directories(my_project PUBLIC mylib)
# `my_project` 依赖 `mylib`
target_link_libraries(my_project PRIVATE mylib)