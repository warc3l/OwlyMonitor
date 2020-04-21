
all: 
	g++ -std=c++14 -lpthread src/main.cc src/Device.cc src/CounterSubscriber.cc src/Monitor.cc -I./include -lpthread -o MonitorCpp
