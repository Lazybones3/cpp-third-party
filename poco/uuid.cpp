#include <iostream>
#include "Poco/UUIDGenerator.h"
#include "Poco/UUID.h"

int main()
{
    // 使用默认的UUID生成器
    Poco::UUIDGenerator generator;
    // 生成一个随机UUID
    Poco::UUID uuid1 = generator.createRandom();
    // 生成一个基于时间的UUID
    Poco::UUID uuid2 = generator.createOne();
    std::cout << "Random UUID: " << uuid1.toString() << std::endl;
    std::cout << "Time-based UUID: " << uuid2.toString() << std::endl;

    return 0;
}