#ifndef _COUNTER_SUBSCRIBER_HPP
#define _COUNTER_SUBSCRIBER_HPP

#include "AbstractSubscriber.hpp"

class CounterSubscriber : public AbstractSubscriber { 
    public:
        static long long counter;
        void recv(DeviceData& d) override;
};

#endif
