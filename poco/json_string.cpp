#include <iostream>
#include <fstream>
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/Dynamic/Var.h"


int main() {
    // 解析json
    std::string jsonString = R"({"name":"John", "age":30, "city":"New York"})";
    // 创建json解析器
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result;

    try
    {
        // 解析json字符串
        result = parser.parse(jsonString);
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

    // 创建json对象
    Poco::JSON::Object jsonObject;
    // 添加键值对
    jsonObject.set("name", "John");
    jsonObject.set("age", 30);
    jsonObject.set("city", "New York");
    // 将json对象转为字符串
    std::ostringstream oss;
    Poco::JSON::Stringifier::stringify(jsonObject, oss);

    std::string jsonString2 = oss.str();
    // 打印生成的json字符串
    std::cout << jsonString2 << std::endl;

    return 0;
}