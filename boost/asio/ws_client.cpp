#include <iostream>
#include <chrono>
#include <thread>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/io_context.hpp>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
using tcp = boost::asio::ip::tcp;

void runWebSocketClient(const std::string& serverAddress, unsigned short port) {
    try {
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        websocket::stream<tcp::socket> ws(io_context);

        auto const results = resolver.resolve(serverAddress, std::to_string(port));
        boost::asio::connect(ws.next_layer(), results.begin(), results.end());
        ws.handshake(serverAddress, "/");

        while (true) {
            std::string message = "Hello, WebSocket!";
            ws.write(boost::asio::buffer(message));

            beast::flat_buffer buffer;
            ws.read(buffer);
            std::cout << "Server response: " << beast::buffers_to_string(buffer.data()) << " port: " << port << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        // ws.close(websocket::close_code::normal);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "WebSocket client example" << std::endl;

    std::string serverAddress = "localhost";
    unsigned short port = 9002;
    runWebSocketClient(serverAddress, port);

    // 可在多线程中开启多个端口
    // unsigned short port2 = 9003;
    // runWebSocketClient(serverAddress, port2);

    return 0;
}
