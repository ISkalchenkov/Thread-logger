//
// Created by antarctica on 06.03.2021.
//

#include "loggers/BaseLogger.hpp"

namespace log {

    BaseLogger::BaseLogger() noexcept: level_(Level::INFO) {
    }

    BaseLogger::BaseLogger(Level lvl) noexcept: level_(lvl) {
    }

    void BaseLogger::debug(const std::string &msg) {
        log(msg, Level::DEBUG);
    }

    void BaseLogger::info(const std::string &msg) {
        log(msg, Level::INFO);
    }

    void BaseLogger::warning(const std::string &msg) {
        log(msg, Level::WARNING);
    }

    void BaseLogger::error(const std::string &msg) {
        log(msg, Level::ERROR);
    }

    void BaseLogger::fatal(const std::string &msg) {
        log(msg, Level::FATAL);
    }

    void BaseLogger::set_level(const Level lvl) noexcept {
        level_ = lvl;
    }

    Level BaseLogger::level() const noexcept {
        return level_;
    }

} // namespace log
