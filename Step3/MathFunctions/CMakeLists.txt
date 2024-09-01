# 设置一个变量，表示是否使用自己的库
option(USE_MYMATH "Use custom square root implementation" ON)

# 添加一个库，后面的参数是库的源文件（.c,.cpp,.cxx）
# 默认静态库
add_library(MathFunctions MathFunctions.cxx )

# 选项USE_MYMATH为ON时，添加自己的库
if (USE_MYMATH)
# 创建库
  add_library(SqrtLibrary mysqrt.cxx)
  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
# 链接库
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
# 为 MathFunctions 目标设置了一个名为 USE_MYMATH 的编译定义（也可以称为预处理器宏）。
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()
# 将当前目录添加到 MathFunctions 的接口包含目录中
# 并且MathFunctions指定被其他的目标链接时，会将这个目录添加到包含目录中
# INTERFACE表示包含目录将应用于目标及其使用该目标的其他目标。
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
# 将tutorial_compiler_flags链接到MathFunctions

target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)