#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

int main()
{
    boost::asio::io_context io_context;

    // 创建UDP端点并绑定到任意端口
    udp::socket socket(io_context, udp::endpoint(udp::v4(), 0));

    // 远程服务器端点
    udp::endpoint remote_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8888);

    // 发送数据
    std::string message = "Hello from client!";
    socket.send_to(boost::asio::buffer(message), remote_endpoint);

    // 接收缓冲区
    char recv_buffer[1024];

    // 接收回复
    udp::endpoint sender_endpoint;
    size_t bytes_received = socket.receive_from(boost::asio::buffer(recv_buffer), sender_endpoint);

    // 打印回复数据
    std::cout.write(recv_buffer, bytes_received);
    std::cout << std::endl;

    return 0;
}
