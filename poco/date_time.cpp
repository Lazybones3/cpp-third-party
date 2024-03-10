#include <iostream>
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"

int main()
{
    // 获取挡墙日期和时间
    Poco::DateTime now;
    // 格式化日期和时间为字符串
    std::string formatterDateTime = Poco::DateTimeFormatter::format(now, "%Y-%m-%d %H:%M:%S");
    // 输出格式化之后的日期和时间
    std::cout << "Formatted Date and Time: " << formatterDateTime << std::endl;

    // 获取日期部分
    Poco::DateTime date(now.year(), now.month(), now.day());
    // 格式化日期为字符串
    std::string formatterDate = Poco::DateTimeFormatter::format(date, "%Y-%m-%d");
    std::cout << "Formatted Date: " << formatterDate << std::endl;

    return 0;
}