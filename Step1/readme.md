# CMake 教程 - 一、快速上手

## 介绍

这一步介绍了CMake的基本语法、命令和变量，完成一个简单的CMake项目。

## 练习 1: 构建一个基本项目

在一个目录下新建`Step1`目录
在该新建目录中新建tutorial.cxx（其实就是c++文件）
复制粘贴下面的内容：
~~~cpp
// tutorial.cxx

#include <cmath>
#include <iostream>
#include <string>
#include "TutorialConfig.h"
// 定义版本信息
#define Tutorial_VERSION_MAJOR 1
#define Tutorial_VERSION_MINOR 0

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        // report version
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
                  << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    // 将输入字符串转换为double
    const double inputValue = std::stod(argv[1]);

    // 计算平方根
    const double outputValue = std::sqrt(inputValue);

    // 输出结果
    std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;

    return 0;
}

~~~

最基本的CMake项目是从一个单一的源文件构建一个可执行文件，做到这样至少需要三个CMake命令：

### 步骤

1. **指定CMake版本，确保cmake兼容性**：
    ```cmake
    cmake_minimum_required(VERSION 3.10)
    ```
2. **设置项目名称，有一些变量会与项目名称挂钩**：
    ```cmake
    project(Tutorial)
    ```
3. **添加可执行文件，最起码输出的可执行文件得知道是啥**：
    ```cmake
    add_executable(Tutorial tutorial.cxx)
    ```

### 构建和运行

- 创建构建目录（新建文件夹：
    ```bash
    mkdir Step1_build
    ```
- 进入构建目录并配置项目（让cmake根据CMakeLists自动生成编译的步骤和实现：
    ```bash
    cd Step1_build
    cmake ../Step1
    ```
- 构建项目，根据cmake生成的编译步骤编译：
    ```bash
    cmake --build .
    ```
- 运行可执行文件：
    ```bash
    ./Tutorial 10
    ```

由上可以看出，cmake的作用是隔离平台的不同，通过一个CMakeLists生成在不同的平台的编译过程并可以通过cmake命令执行
## 练习 2: 指定C++标准

在这个练习中，学习如何指定一个特定的C++标准，如C++11。

### 步骤

1. **在 `tutorial.cxx` 中用 `std::stod` 替换 `atof`**：
    ```cpp
    const double inputValue = std::stod(argv[1]);
    ```
2. **移除不必要的 `#include` 指令**：
    ```cpp
    // 移除: #include <cstdlib>
    ```
3. **在 `CMakeLists.txt` 中指定C++11标准**：
    ```cmake
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
    ```

### 构建和运行

- 重新进入构建目录并构建项目：
    ```bash
    cd Step1_build
    cmake --build .
    ```
- 运行可执行文件：
    ```bash
    ./Tutorial 10
    ```

## 练习 3: 添加版本号和配置头文件

有时我们希望在源代码中使用在 `CMakeLists.txt` 中定义的变量。在这个练习中，我们将添加一个项目的版本号并打印出来。

### 步骤

1. **在 `CMakeLists.txt` 中定义项目版本号**：
    ```cmake
    project(Tutorial VERSION 1.0)
    ```
2. **使用 `configure_file` 命令创建配置文件**：
    ```cmake
    configure_file(
      "${CMAKE_CURRENT_SOURCE_DIR}/TutorialConfig.h.in"
      "${CMAKE_CURRENT_BINARY_DIR}/TutorialConfig.h"
    )
    官方CMake教程对configure_file的解释是：复制一份输入文件到输出文件，替换输入文件中被@VAR@或者${VAR}引用的变量值。也就是说，让普通文件，也能使用CMake中的变量。
    ```
3. **在 `CMakeLists.txt` 中指定包含路径**：
    ```cmake
    target_include_directories(Tutorial PUBLIC
                               "${CMAKE_CURRENT_BINARY_DIR}"
                               )
    # 通过打印头文件信息，可以看到包含目录的添加结果
    get_target_property(INCLUDE_DIRS Tutorial INCLUDE_DIRECTORIES)
    message(STATUS "Include directories for Tutorial: ${INCLUDE_DIRS}")
    ```
4. **在 `tutorial.cxx` 中包含配置头文件**：
    ```cpp
    #include "TutorialConfig.h"
    ```
5. **打印版本号**：
    ```cpp
    # 可以读取到构建目录下头文件中替换后的变量值
    std::cout << "Tutorial Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    ```

### 构建和运行

- 重新构建项目并运行：
    ```bash
    cd Step1_build
    cmake --build .
    ./Tutorial
    ```

此时可以看到程序输出项目的版本号。
