#include <iostream>
#include <boost/beast.hpp>
#include <boost/asio.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

void handle_request(http::request<http::string_body> &request, http::response<http::string_body> &response)
{
    std::cout << "Request method: " << request.method() << std::endl;
    for (auto const &field : request)
    {
        std::cout << field.name() << " : " << field.value() << std::endl;
    }
    // 处理请求并生成响应
    response.version(request.version());
    response.result(http::status::ok);
    response.set(http::field::server, "Boost Beast HTTP Server");
    response.body() = "Hello World!";
    response.prepare_payload();
}

int main()
{
    try
    {
        // 创建IO上下文
        net::io_context io_context;
        // 创建解析器并监听端口
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8881));

        while (true)
        {
            // 接收连接
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            // 读取请求
            beast::flat_buffer buffer;
            http::request<http::string_body> request;
            http::read(socket, buffer, request);
            // 处理请求并生成响应
            http::response<http::string_body> response;
            handle_request(request, response);
            // 发送响应
            http::write(socket, response);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}