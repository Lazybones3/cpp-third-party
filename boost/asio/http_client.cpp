#include <iostream>
#include <boost/beast.hpp>
#include <boost/asio.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

int main()
{
    try
    {
        // 创建IO上下文和解析器
        net::io_context io_context;
        tcp::resolver resolver(io_context);
        beast::tcp_stream stream(io_context);
        // 解析主机和端口
        auto const results = resolver.resolve("localhost", "8881");
        // 连接到服务器
        stream.connect(results);
        // 创建HTTP请求
        http::request<http::string_body> request(http::verb::get, "/", 11);
        request.set(http::field::host, "localhost");
        request.set(http::field::user_agent, "Boost Beast");
        // 发送请求
        http::write(stream, request);
        // 接收并打印响应
        beast::flat_buffer buffer;
        http::response<http::string_body> response;
        http::read(stream, buffer, response);

        std::cout << "Response code: " << response.result_int() << std::endl;
        std::cout << "Response body: " << response.body() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}