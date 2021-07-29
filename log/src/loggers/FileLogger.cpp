//
// Created by antarctica on 06.03.2021.
//

#include <loggers/FileLogger.hpp>

namespace log {

    FileLogger::FileLogger(const std::string &file_path)
        : file_(file_path) {
        if (!file_) {
            throw std::runtime_error("Can't open file '" + file_path + "'");
        }
    }

    FileLogger::FileLogger(const std::string &file_path, Level lvl)
        : file_(file_path)
        , BaseLogger(lvl) {
        if (!file_) {
            throw std::runtime_error("Can't open file '" + file_path + "'");
        }
    }

    void FileLogger::flush() noexcept {
        file_.flush();
    }

    void FileLogger::log(const std::string &msg, Level lvl) {
        if (lvl >= level()) {
            file_ << msg << '\n';
        }
    }

} // namespace log
