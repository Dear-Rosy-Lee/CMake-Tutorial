cmake_minimum_required(VERSION 3.10)
project(Tutorial VERSION 1.0)
# c++17中sqrt不必include cmath
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 这一行的作用是告诉 CMake 在构建过程中需要进入 MathFunctions 子目录，
# 并处理该目录中的 CMakeLists.txt 文件。
# 这个目录中的 CMakeLists.txt 文件定义了 MathFunctions 库的具体内容。
# 通过这个命令，CMake 会在链接 Tutorial 可执行文件前先根据MathFunctions目录中CMakeLists.txt构建出MathFunctions库。
add_subdirectory(MathFunctions)
# 先确定 Tutorial 可执行文件的名称，然后列出需要链接的库和头文件目录。
add_executable(Tutorial tutorial.cxx) 
# 将 MathFunctions 库链接到 Tutorial 可执行文件上
target_link_libraries(Tutorial PUBLIC MathFunctions)
# 将 PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR 添加到 include 目录中，
# 这样 Tutorial 可执行文件就可以找到 MathFunctions.h 文件了。
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/MathFunctions"  
                           )
