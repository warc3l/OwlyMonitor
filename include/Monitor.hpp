#ifndef _MONITOR_HPP
#define _MONITOR_HPP

#include <list>
#include <queue>
#include <mutex>
#include <thread>
#include "DeviceData.hpp"
#include "CounterSubscriber.hpp"

// singleton
class Monitor {
    private: 
        std::mutex guard;
        Monitor() = default;
        static Monitor* _instance;
        std::queue<DeviceData> _q;
        std::list<AbstractSubscriber*> _s;
        std::thread _t;

        void initSubscribers();
        void initThread();

    public:
        static Monitor* getInstance();
        void push(const DeviceData& dd);

        inline void processQueue();
};

#endif
