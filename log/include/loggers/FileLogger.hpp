//
// Created by antarctica on 06.03.2021.
//

#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <fstream>

#include "BaseLogger.hpp"

namespace log {

    class FileLogger final : public BaseLogger {
    public:
        explicit FileLogger(const std::string& file_path);
        FileLogger(const std::string& file_path, Level lvl);

        void flush() noexcept override;

    private:
        std::ofstream file_;

        void log(const std::string& msg, Level lvl) override;
    };

} // namespace log

#endif
