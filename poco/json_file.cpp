#include <iostream>
#include <fstream>
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/Dynamic/Var.h"


int main() {
    // 创建json对象
    Poco::JSON::Object jsonObject;
    // 添加键值对
    jsonObject.set("name", "John");
    jsonObject.set("age", 30);
    jsonObject.set("city", "New York");
    // 将json对象转为字符串
    std::ostringstream oss;
    Poco::JSON::Stringifier::stringify(jsonObject, oss);

    std::string jsonString = oss.str();
    // 打印生成的json字符串
    std::cout << jsonString << std::endl;

    // 写入json字符串到文件
    std::ofstream ofile("data.json");
    if (ofile.is_open())
    {
        ofile << jsonString;
        ofile.close();
        std::cout << "JSON data has been written to file." << std::endl;
    } else {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    // 从文件中解析json
    std::ifstream ifile("data.json");
    if (!ifile.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }
    std::string jsonString2((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());
    
    // 创建json解析器
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result;

    try
    {
        // 解析json字符串
        result = parser.parse(jsonString2);
    }
    catch(const Poco::Exception& e)
    {
        std::cerr << "JSON parsing error: " << e.displayText() << std::endl;
        return 1;
    }

    // 将解析结果转换为Object类型
    Poco::JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
    // 获取和操作json对象中的值
    std::string name = object->getValue<std::string>("name");
    int age = object->getValue<int>("age");
    std::string city = object->getValue<std::string>("city");
    // 打印结果
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "City: " << city << std::endl;

    return 0;
}