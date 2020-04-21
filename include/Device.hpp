#ifndef _DEVICE_HPP
#define _DEVICE_HPP

#include <chrono>

#include "DeviceData.hpp"
#include "Monitor.hpp"

using namespace std::chrono_literals;

// publisher
class Device {
    private:
        DeviceData dd;
        void notify();

        decltype(1ms) t;

    public:
        Device() = delete;
        Device(float init_value, unsigned int id, decltype(1ms) t = 1ms);
        void update();
};

#endif
