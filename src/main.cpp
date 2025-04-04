#include<iostream>
#include<memory>
#include <boost/signals2.hpp>

#include"utils.h"
#include"helper.h"
#include"lib.h"

// 定义信号类型
boost::signals2::signal<void (int)> onValueChanged;
// 定义槽函数
void onValueChangedSlot(int value) {
    std::cout << "Value changed: " << value << std::endl;
}

int main()
{
    // 输出Hello, World!
    std::cout << "Hello, World!" << std::endl;

    // 调用lib.h中的函数
    std::cout << "Calling lib.h function..." << std::endl;
    std::unique_ptr<lib> my_lib = std::make_unique<lib>();
    my_lib->showInfo();

    // 调佣utils.h中的函数
    std::cout << "Calling utils.h function..." << std::endl;
    std::unique_ptr<utils> my_utils = std::make_unique<utils>();
    my_utils->showInfo();

    // 调用helper.h中的函数
    std::cout << "Calling helper.h function..." << std::endl;
    std::unique_ptr<helper> my_helper = std::make_unique<helper>();
    my_helper->showInfo();

    // // 连接信号和槽
    // std::cout << "Connecting signal and slot..." << std::endl;
    // onValueChanged.connect(onValueChangedSlot);
    // // 触发信号
    // std::cout << "Emitting signal..." << std::endl;
    // onValueChanged(42); // 触发信号，传递参数42
    // // 断开信号和槽的连接
    // std::cout << "Disconnecting signal and slot..." << std::endl;
    // onValueChanged.disconnect(onValueChangedSlot);
    
    // 返回0
    return 0;
}