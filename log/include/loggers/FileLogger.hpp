//
// Created by antarctica on 06.03.2021.
//

#ifndef FILE_LOGGER_HPP
#define FILE_LOGGER_HPP

#include <fstream>
#include <memory>

#include "BaseLogger.hpp"

namespace log {

    class FileLogger final : public BaseLogger {
    public:
        FileLogger(const std::string& file_path, Level lvl);

        void flush() override;

    private:
        std::ofstream file_;

        void log(const std::string& msg, Level lvl) override;
    };

    std::unique_ptr<FileLogger> create_file_logger(const std::string& file_path, Level lvl);

} // namespace log

#endif // FILE_LOGGER_HPP
