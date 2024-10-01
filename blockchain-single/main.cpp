#include <iostream>
#include <chrono>

#include "elements/Blockchain.hpp"

int main() {
    auto bChain = Blockchain(6);

    const auto start = std::chrono::high_resolution_clock::now();

    bChain.AddBlock("hola");
    bChain.AddBlock("adios");

    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds." << std::endl;


    return 0;
}
