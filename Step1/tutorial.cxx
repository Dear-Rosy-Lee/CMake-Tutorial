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
