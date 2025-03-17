#include<iostream>
#include<memory>

#include"utils.h"
#include"helper.h"
#include"lib.h"

int main()
{
    // 输出Hello, World!
    std::cout << "Hello, World!" << std::endl;
    // 调用lib.h中的函数
    std::unique_ptr<lib> my_lib = std::make_unique<lib>();
    my_lib->showInfo();
    // 调佣utils.h中的函数
    std::unique_ptr<utils> my_utils = std::make_unique<utils>();
    my_utils->showInfo();
    // 调用helper.h中的函数
    std::unique_ptr<helper> my_helper = std::make_unique<helper>();
    my_helper->showInfo();
    // 返回0
    return 0;
}