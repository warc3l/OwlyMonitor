#include "Device.hpp"

Device::Device(float init_value, unsigned int id, decltype(1ms) p_t) {
    dd.setUID(id);
    dd.setValue(init_value);
    t = p_t;
}

void Device::notify() {
    Monitor::getInstance()->push(dd);
}

void Device::update() {
    while( true ) {
        notify();
        std::this_thread::sleep_for(t);
    }
}
