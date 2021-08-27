//
// Created by antarctica on 11.08.2021.
//

#include <sstream>

#include "loggers/ThreadedLogger.hpp"
#include "loggers/StdoutLogger.hpp"

int main() {
    log::init(log::create_stdout_logger(log::Level::DEBUG,
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
