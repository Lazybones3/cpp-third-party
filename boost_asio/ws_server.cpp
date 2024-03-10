#include <iostream>
#include <string>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
using tcp = boost::asio::ip::tcp;

void runWebSocketServer(unsigned short port) {
    try {
        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
        tcp::socket socket(io_context);
        acceptor.accept(socket);

        websocket::stream<tcp::socket> ws(std::move(socket));
        ws.accept();

        while (true) {
            beast::flat_buffer buffer;
            ws.read(buffer);

            std::string message(beast::buffers_to_string(buffer.data()));
            std::cout << "Received message: " << message << " port: " << port << std::endl;

            ws.text(ws.got_text());
            ws.write(boost::asio::buffer("Response: " + message));
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "WebSocket server is running..." << std::endl;

    unsigned short port = 9002;
    runWebSocketServer(port);

    // 可在多线程中开启多个端口
    // unsigned short port2 = 9003;
    // runWebSocketServer(port2);

    return 0;
}
