#include "CounterSubscriber.hpp"

long long CounterSubscriber::counter = 0;

void CounterSubscriber::recv(DeviceData& d) {
    // ...
    counter++;
}
