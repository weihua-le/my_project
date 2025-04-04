# 设置CMake政策以避免警告
cmake_policy(SET CMP0167 NEW)

# 查找Boost库
set(CMAKE_PREFIX_PATH "E:/ThirdPartyPackages/vcpkg/installed/x64-windows/share/boost")
find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found")
endif()

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
target_link_libraries(my_project PRIVATE mylib)

if(Boost_FOUND)
    target_link_libraries(my_project PUBLIC ${Boost_LIBRARIES})
endif()