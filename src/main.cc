
#include <iostream>
#include <chrono>
#include <thread>

#include "Device.hpp"

using namespace std::chrono_literals;

int main() {

    Device A(10.3, 2, 1000ms);
    Device B(13, 1, 3ms);
    Device C(213.314, 0);

    std::thread firstThread(&Device::update, &A);
    std::thread secondThread(&Device::update, &B);
    std::thread thirdThread(&Device::update, &C);

    while (true) {
        std::cout << "Counter equals: " << CounterSubscriber::counter << std::endl;
        std::this_thread::sleep_for(5s);
    }

    firstThread.join();
    secondThread.join();
    thirdThread.join();

    return 0;
}
