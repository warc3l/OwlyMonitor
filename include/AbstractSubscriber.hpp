#ifndef _ABSTRACT_SUBSCRIBER_HPP
#define _ABSTRACT_SUBSCRIBER_HPP

#include "DeviceData.hpp"

class AbstractSubscriber {
    public:
        virtual void recv(DeviceData& dd) = 0; 
};

#endif
