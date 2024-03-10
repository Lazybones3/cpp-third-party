#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

int main()
{
    boost::asio::io_context io_context;

    // 创建UDP端点并绑定到特定端口
    udp::socket socket(io_context, udp::endpoint(udp::v4(), 8888));

    // 接收缓冲区
    char recv_buffer[1024];

    while (true) {
        udp::endpoint remote_endpoint;

        // 接收数据
        size_t bytes_received = socket.receive_from(boost::asio::buffer(recv_buffer), remote_endpoint);

        // 打印接收到的数据
        std::cout.write(recv_buffer, bytes_received);
        std::cout << std::endl;

        // 发送回复
        std::string message = "Hello from server!";
        socket.send_to(boost::asio::buffer(message), remote_endpoint);
    }

    return 0;
}
