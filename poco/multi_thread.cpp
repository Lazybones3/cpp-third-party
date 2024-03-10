#include <iostream>
#include "Poco/Thread.h"
#include "Poco/Runnable.h"

class MyTask : public Poco::Runnable
{
public:
    void run() override
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Thread ID: " << Poco::Thread::currentTid()
                      << "  Task ID: " << i << std::endl;
            Poco::Thread::sleep(1000);
        }
    }
};

int main()
{
    // 创建线程任务对象
    MyTask task;
    // 创建线程对象并启动
    Poco::Thread thread;
    thread.start(task);

    // 主线程继续执行其他任务
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Main Thread ID: " << Poco::Thread::currentTid()
                  << "  Main Task ID: " << i << std::endl;
        Poco::Thread::sleep(500);
    }

    // 等待子线程结束
    thread.join();

    return 0;
}