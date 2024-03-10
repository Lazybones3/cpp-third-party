#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <thread>

namespace asio = boost::asio;
namespace beast = boost::beast;
using tcp = asio::ip::tcp;

void SendMessages(beast::websocket::stream<tcp::socket>& ws) {
    try {
        // Send a message every 1 seconds
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            ws.write(asio::buffer("Server: Sending a message from the server!"));
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception in SendMessages: " << e.what() << std::endl;
    }
}

int main() {
    try {
        asio::io_context io_context;

        // Create and bind the acceptor
        tcp::acceptor acceptor(io_context, {tcp::v4(), 8881});

        while (true) {
            // Accept connection
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            // WebSocket upgrade
            beast::websocket::stream<tcp::socket> ws(std::move(socket));
            ws.accept();

            // Start a thread to send messages to the client
            std::thread senderThread(SendMessages, std::ref(ws));

            // Read WebSocket message
            beast::flat_buffer buffer;
            ws.read(buffer);

            // Print received message
            std::cout << "Received: " << beast::buffers_to_string(buffer.data()) << std::endl;

            // Echo the message back to the client
            ws.text(ws.got_text());
            ws.write(buffer.data());

            // Join the sender thread
            senderThread.join();
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
