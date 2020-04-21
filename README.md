#### Technical Test by Marcel Vilalta

This code aims to resolve an specific problem, that monitors a set of devices that are sending data periodically.

It is written in C++14, using the chrono literals and the \<thread> library from the standard.

#### Proposed solution

The Software Architecture uses the Publisher-Subscription design pattern to resolve it. Each of the Devices are Publishers, and, the counter is incremented by a Subscriber, a _CounterSubscriber_.

I think that it is the best solution for this problem due to each Devices are constantly pushing new data on a queue in an undefined time, which is emulated by the creation of three different threads. 

That's it, the Monitor will consume the queue on an independent thread, which is filled by different devices on different threads. The Monitor will be countinously polling the elements of the queue.

I implement an AbstractSubscriber pure base virtual class to make it easy the creation of new subscribers if needed (Ex: the update of a data base when a Device notifies changes). 

The number of messages is shown on console in the main function.

#### Run Code

The code is written for Linux, because the STL \<thread> library is not available on Windows by g++. To compile the code, there is a Makefile, which produces the executable called MonitorCpp:

```
make all
```

Or, there is a possibility to run it into a Docker image. You should create the image by:

```
docker build -t mw/monitor .
```

And then, to Compile it, there is a purposed script to do that in Windows, called _CompileThroughDocker.bat_.

```
CompileThroughDocker.bat
```

Finally, to Run the code, you should be able to run the container, and then, execute the Software into it, by:

```
RunContainer.bat
$> ./test/MonitorCpp
```


