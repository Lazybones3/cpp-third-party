#include <iostream>
#include <boost/thread.hpp>

// 线程函数
void threadFunction()
{
    std::cout << "Thread ID: " << boost::this_thread::get_id() << std::endl;
    std::cout << "Hello from a thread!" << std::endl;
}

int main()
{
    // 创建线程并启动
    boost::thread threadObj(threadFunction);

    // 等待线程结束
    threadObj.join();

    // 输出主线程相关信息
    std::cout << "Main Thread ID: " << boost::this_thread::get_id() << std::endl;
    std::cout << "Main thread exiting..." << std::endl;
    return 0;
}