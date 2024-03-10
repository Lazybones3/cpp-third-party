#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
    try
    {
        boost::asio::io_context io_context;
        // 创建一个TCP acceptor，监听端口
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8081));
        // 等待并接收连接
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        // 接收客户端的消息
        char response[1024];
        size_t bytesRead = socket.read_some(boost::asio::buffer(response));

        std::cout << "Response from client: ";
        std::cout.write(response, bytesRead);
        // 处理连接请求
        std::string message = "Hello, Boost.Asio!";
        boost::system::error_code ignored_error;
        boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}