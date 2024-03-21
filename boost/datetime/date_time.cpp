#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

long GetTime();

int main()
{
    // 获取当前系统时间
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    std::cout << "Current system time: " << now << std::endl;
   
    // 格式化输出当前系统时间
    std::string formattedTime = boost::posix_time::to_simple_string(now);
    std::cout << "Formatted current system time: " << formattedTime << std::endl;
   
    // 日期增减
    boost::posix_time::ptime tomorrow = now + boost::gregorian::days(1);
    std::cout << "Tomorrow: " << tomorrow << std::endl;
   
    // 时间增减
    boost::posix_time::ptime nextHour = now + boost::posix_time::hours(1);
    std::cout << "Next hour: " << nextHour << std::endl;

    // 时间差计算
    boost::posix_time::time_duration diff = nextHour - now;
    std::cout << "Difference between now and next hour: " << diff.total_seconds() << " seconds" << std::endl;

    // 获取当前系统时间，精确到毫秒
    boost::posix_time::ptime now_ms = boost::posix_time::microsec_clock::local_time();
    // 将时间转换为毫秒
    boost::posix_time::time_duration duration = now_ms.time_of_day();
    long milliseconds = duration.total_milliseconds();
    // 输出毫秒级时间
    std::cout << "Current system milliseconds: " << milliseconds << std::endl;

    long t1 = GetTime();
    sleep(1);
    long t2 = GetTime();
    // 输出时间差
    std::cout << "This program cost: " << t2 - t1 << std::endl;

    return 0;
}

long GetTime()
{
    boost::posix_time::ptime now_ms = boost::posix_time::microsec_clock::local_time();
    boost::posix_time::time_duration duration = now_ms.time_of_day();
    long milliseconds = duration.total_milliseconds();
    return milliseconds;
}
