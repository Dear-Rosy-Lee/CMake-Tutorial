option(USE_MYMATH "Use custom square root implementation" ON)

# 添加一个库，后面的参数是库的源文件（.c,.cpp,.cxx）
# 默认静态库
add_library(MathFunctions MathFunctions.cxx )
# 选项USE_MYMATH为ON时，添加自己的库
if (USE_MYMATH)
# 创建库
  add_library(SqrtLibrary mysqrt.cxx)
# 链接库
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
# 为 MathFunctions 目标设置了一个名为 USE_MYMATH 的编译定义（也可以称为预处理器宏）。
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()