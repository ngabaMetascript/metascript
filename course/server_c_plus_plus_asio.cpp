/*

    Boost.Asio : A powerful C++ library for networking and I/O management. It allows you to manage sockets and connections asynchronously, which is useful for creating a high-performance server..

    to install Boost : sudo apt-get install libboost-all-dev  # Sur Linux

An example of simple server
*/

#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

int main() {
    io_service io_service;

    // On crée un endpoint pour écouter sur le port 8080
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080));

    while (true) {
        // On accepte une nouvelle connexion
        tcp::socket socket(io_service);
        acceptor.accept(socket);

        // On lit la requête du client
        boost::asio::streambuf request;
        read_until(socket, request, "\r\n");

        // On traite la requête et on envoie une réponse
        std::string response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n\r\n"
            "<html><body><h1>Hello, World!</h1></body></html>";

        write(socket, buffer(response));
    }

    return 0;
}

