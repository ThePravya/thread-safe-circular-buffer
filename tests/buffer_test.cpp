#include <iostream>
#include <thread>
#include <chrono>
#include "CircularBuffer.hpp"

int main() {
    CircularBuffer<int> buffer(5);

    std::thread producer([&buffer]() {
        for (int i = 1; i <= 10; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            buffer.push(i);
            std::cout << "Produced: " << i << std::endl;
        }
    });

    std::thread consumer([&buffer]() {
        for (int i = 1; i <= 10; ++i) {
            int value = buffer.pop();
            std::cout << "Consumed: " << value << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
