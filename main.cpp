#include<iostream>
#include<memory>

#include"utils.h"

int main()
{
    // 输出Hello, World!
    std::cout << "Hello, World!" << std::endl;
    // 调佣utils.h中的函数
    std::unique_ptr<utils> my_utils = std::make_unique<utils>();
    my_utils->showInfo();
    // 返回0
    return 0;
}