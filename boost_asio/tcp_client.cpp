#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
    try
    {
        // 创建IO上下文
        boost::asio::io_context io_context;
        // 创建socket对象
        tcp::socket socket(io_context);
        // 解析服务器地址和端口
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("localhost", "8081");
        // 连接到服务器
        boost::asio::connect(socket, endpoints);
        // 发送数据给服务器
        std::string request = "Hello, server!";
        boost::asio::write(socket, boost::asio::buffer(request));
        // 接收服务器的响应
        char response[1024];
        size_t bytesRead = socket.read_some(boost::asio::buffer(response));
        // 显示服务器的响应
        std::cout << "Response from server: ";
        std::cout.write(response, bytesRead);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}