#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace asio = boost::asio;
namespace beast = boost::beast;
using tcp = asio::ip::tcp;

int main() {
    try {
        asio::io_context io_context;

        // Resolve the host name
        tcp::resolver resolver(io_context);
        auto const results = resolver.resolve("localhost", "8881");

        // Connect to the server
        tcp::socket socket(io_context);
        asio::connect(socket, results);

        // WebSocket upgrade
        beast::websocket::stream<tcp::socket> ws(std::move(socket));
        ws.handshake("localhost", "/");

        // Receive and print the initial message from the server
        beast::flat_buffer buffer;
        ws.read(buffer);
        std::cout << "Received: " << beast::buffers_to_string(buffer.data()) << std::endl;

        // Start a thread to continuously receive messages from the server
        std::thread receiverThread([&ws] {
            try {
                while (true) {
                    beast::flat_buffer buffer;
                    ws.read(buffer);
                    std::cout << "Received: " << beast::buffers_to_string(buffer.data()) << std::endl;
                }
            } catch (const std::exception &e) {
                std::cerr << "Exception in receiverThread: " << e.what() << std::endl;
            }
        });

        // Send a WebSocket message
        ws.text(true);
        ws.write(asio::buffer("Client: Hello, Server!"));

        // Join the receiver thread
        receiverThread.join();

        // Close the WebSocket connection
        ws.close(beast::websocket::close_code::normal);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
