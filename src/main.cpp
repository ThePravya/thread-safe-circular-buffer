#include <iostream>
#include <thread>
#include <chrono>
#include "CircularBuffer.hpp"

int main()
{
    // Create a circular buffer with fixed capacity = 5
    // This buffer is assumed to be thread-safe and blocking.
    CircularBuffer<int> buffer(5);

    // ----------------------------
    // Producer Thread
    // ----------------------------
    // Pushes integers 1 to 10 into the buffer.
    // If the buffer becomes full, push() will block
    // until the consumer removes an element.
    std::thread producer([&buffer]()
    {
        for (int i = 1; i <= 10; ++i)
        {
            // Simulate production delay
            std::this_thread::sleep_for(std::chrono::milliseconds(200));

            // Blocking push (waits if buffer is full)
            buffer.push(i);

            std::cout << "Produced: " << i << std::endl;
        }
    });

    // ----------------------------
    // Consumer Thread
    // ----------------------------
    // Pops 10 integers from the buffer.
    // If the buffer is empty, pop() will block
    // until the producer inserts a new element.
    std::thread consumer([&buffer]()
    {
        for (int i = 1; i <= 10; ++i)
        {
            // Blocking pop (waits if buffer is empty)
            int value = buffer.pop();

            std::cout << "Consumed: " << value << std::endl;

            // Simulate processing delay
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    // Wait for both threads to complete execution
    producer.join();
    consumer.join();

    // RAII ensures std::thread resources are cleaned up properly
    return 0;
}
