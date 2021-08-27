//
// Created by antarctica on 06.03.2021.
//

#include "loggers/FileLogger.hpp"
#include "loggers/StdoutLogger.hpp"
#include "loggers/StderrLogger.hpp"
#include "loggers/Logger.hpp"

int main() {
    log::init(log::create_stdout_logger(log::Level::DEBUG,
                                        std::make_shared<log::LogFormatter>(log::mod::ALL)));
    log::debug("Debug message");
    log::info("Info message");
    log::warning("Warning message");
    log::error("Error message");
    log::fatal("Fatal message");

    log::init(log::create_stderr_logger(log::Level::DEBUG,
                                        std::make_shared<log::LogFormatter>(log::mod::TIME | log::mod::LEVEL)));
    log::debug("Debug message");
    log::info("Info message");
    log::warning("Warning message");
    log::error("Error message");
    log::fatal("Fatal message");

    log::init(log::create_file_logger("log.log", log::Level::DEBUG));
    log::debug("Debug message");
    log::info("Info message");
    log::warning("Warning message");
    log::error("Error message");
    log::fatal("Fatal message");
}
