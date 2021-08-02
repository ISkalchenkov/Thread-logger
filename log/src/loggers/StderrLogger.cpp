//
// Created by antarctica on 06.03.2021.
//

#include <iostream>

#include "loggers/StderrLogger.hpp"

namespace log {

    StderrLogger::StderrLogger(Level lvl) noexcept
        : BaseLogger(lvl) {
    }

    void StderrLogger::flush() {
        std::cerr.flush();
    }

    void StderrLogger::log(const std::string &msg, Level lvl) {
        if (lvl >= level()) {
            std::cerr << msg << '\n';
        }
    }

    std::unique_ptr<StderrLogger> create_stderr_logger(Level lvl) {
        return std::make_unique<StderrLogger>(lvl);
    }

} // namespace log
