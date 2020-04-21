#include "Monitor.hpp"

Monitor* Monitor::_instance = nullptr; 

Monitor* Monitor::getInstance() {
    if ( _instance == nullptr ) {
        _instance = new Monitor;
        _instance->initSubscribers();
        _instance->initThread();
    }
    return _instance;
}

void Monitor::initSubscribers() {
    _s.push_back(new CounterSubscriber);
}

void Monitor::initThread() {
    _t = std::thread([this]() { while(true) { processQueue(); } } );
}

void Monitor::push(const DeviceData& dd) {
    _q.push(dd);
}

void Monitor::processQueue() {
    while ( !_q.empty() ) {
        DeviceData data = _q.front();
        _q.pop();     
        for (auto sub: _s) {
            sub->recv(data);
        }       
    }
}
