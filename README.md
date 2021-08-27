## How to build

From this directory
```shell
$ mkdir
$ cd build
$ cmake ..
$ make
```

## Run examples
```shell
$ ./examples/threadedLogging/threadedLogging
$ ./examples/logging/logging
```

## Using the logger
```c++
#include <sstream>

#include "loggers/ThreadedLogger.hpp"
#include "loggers/StdoutLogger.hpp"

int main() {
    log::init(log::create_stdout_logger(log::Level::WARNING,
                                        std::make_shared<log::LogFormatter>(log::mod::ALL)));

    std::vector<std::thread> threads;
    for (size_t i = 0; i < 5; ++i) {
        threads.emplace_back([]() {
            std::ostringstream ss;
            ss << std::this_thread::get_id();
            std::string thread_id = ss.str();

            log::debug_tl("Thread " + thread_id + " : Debug message");
            log::info_tl("Thread " + thread_id + " : Info message");
            log::warning_tl("Thread " + thread_id + " : Warning message");
            log::error_tl("Thread " + thread_id + " : Error message");
            log::fatal_tl("Thread " + thread_id + " : Fatal message");
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}
```

Console output:
```
[Fri Aug 27 23:08:40 2021] : WARN  : Thread 139985775773440 : Warning message
[Fri Aug 27 23:08:40 2021] : WARN  : Thread 139985767380736 : Warning message
[Fri Aug 27 23:08:40 2021] : ERROR : Thread 139985775773440 : Error message
[Fri Aug 27 23:08:40 2021] : ERROR : Thread 139985767380736 : Error message
[Fri Aug 27 23:08:40 2021] : FATAL : Thread 139985775773440 : Fatal message
[Fri Aug 27 23:08:40 2021] : FATAL : Thread 139985767380736 : Fatal message
[Fri Aug 27 23:08:40 2021] : WARN  : Thread 139985758988032 : Warning message
[Fri Aug 27 23:08:40 2021] : ERROR : Thread 139985758988032 : Error message
[Fri Aug 27 23:08:40 2021] : FATAL : Thread 139985758988032 : Fatal message
[Fri Aug 27 23:08:40 2021] : WARN  : Thread 139985667749632 : Warning message
[Fri Aug 27 23:08:40 2021] : ERROR : Thread 139985667749632 : Error message
[Fri Aug 27 23:08:40 2021] : FATAL : Thread 139985667749632 : Fatal message
[Fri Aug 27 23:08:40 2021] : WARN  : Thread 139985659356928 : Warning message
[Fri Aug 27 23:08:40 2021] : ERROR : Thread 139985659356928 : Error message
[Fri Aug 27 23:08:40 2021] : FATAL : Thread 139985659356928 : Fatal message
```
