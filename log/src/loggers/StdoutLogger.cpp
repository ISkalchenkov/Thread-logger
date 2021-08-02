//
// Created by antarctica on 06.03.2021.
//

#include <iostream>

#include "loggers/StdoutLogger.hpp"

namespace log {

    StdoutLogger::StdoutLogger(Level lvl) noexcept
        : BaseLogger(lvl) {
    }

    void StdoutLogger::flush() {
        std::cout.flush();
    }

    void StdoutLogger::log(const std::string &msg, Level lvl) {
        if (lvl >= level()) {
            std::cout << msg << '\n';
        }
    }

    std::unique_ptr<StdoutLogger> create_stdout_logger(Level lvl) {
        return std::make_unique<StdoutLogger>(lvl);
    }
} // namespace log
