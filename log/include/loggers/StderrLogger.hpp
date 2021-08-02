//
// Created by antarctica on 06.03.2021.
//

#ifndef STDERR_LOGGER_HPP
#define STDERR_LOGGER_HPP

#include <memory>

#include "../Level.hpp"
#include "BaseLogger.hpp"

namespace log {

    class StderrLogger final : public BaseLogger {
    public:
        explicit StderrLogger(Level lvl) noexcept;

        void flush() override;

    private:
        void log(const std::string& msg, Level lvl) override;
    };

    std::unique_ptr<StderrLogger> create_stderr_logger(Level lvl);

} // namespace log

#endif // STDERR_LOGGER_HPP
