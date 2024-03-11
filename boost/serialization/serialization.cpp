#include <iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// 序列化和反序列化的示例类
class MyClass
{
public:
    int data;
    double d;
    std::string str;

    // 声明boost序列化函数为友元函数
    friend class boost::serialization::access;

    // 序列化函数
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & data;
        ar & d;
        ar & str;
    }
};

int main()
{
    // 创建一个MyClass对象
    MyClass obj;
    obj.data = 42;
    obj.d = 1.005;
    obj.str = "hello";

    // 将对象序列化到文件
    std::ofstream outputFile("data.txt");
    boost::archive::text_oarchive outputArchive(outputFile);
    outputArchive << obj;
    outputFile.close();

    // 从文件反序列化对象
    std::ifstream inputFile("data.txt");
    boost::archive::text_iarchive inputArchive(inputFile);
    MyClass restoreObj;
    inputArchive >> restoreObj;
    inputFile.close();

    std::cout << "Restored data: " << restoreObj.data << std::endl;
    std::cout << "Restored d: " << restoreObj.d << std::endl;
    std::cout << "Restored str: " << restoreObj.str << std::endl;

    return 0;
}