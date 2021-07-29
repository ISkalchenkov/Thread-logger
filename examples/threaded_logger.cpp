//
// Created by antarctica on 06.03.2021.
//


#include "../log/include/loggers/FileLogger.hpp"
#include "../log/include/loggers/StderrLogger.hpp"
#include "../log/include/loggers/StdoutLogger.hpp"

int main() {
    log::FileLogger logger("log.log");
    logger.debug("Debug");
    logger.info("Info");
    logger.warning("Warning");
    logger.error("Error");
    logger.fatal("Fatal");
}
