//
// Created by antarctica on 06.03.2021.
//

#include <iostream>
#include <string>

#include "../log/include/loggers/FileLogger.hpp"
#include "../log/include/loggers/StderrLogger.hpp"
#include "../log/include/loggers/StdoutLogger.hpp"
#include "../log/include/loggers/Logger.hpp"

int main() {
    log::init(log::create_stdout_logger( log::Level::DEBUG));
    log::debug("Debug");
    log::info("Info");
    log::warning("Warning");
    log::error("Error");
    log::fatal("Fatal");
}
