//
// Created by antarctica on 06.03.2021.
//

#ifndef STDERR_LOGGER_H
#define STDERR_LOGGER_H

#include "../Level.hpp"
#include "BaseLogger.hpp"

namespace log {

    class StderrLogger final : public BaseLogger {
    public:
        StderrLogger() noexcept = default;
        explicit StderrLogger(Level lvl) noexcept;

        void flush() noexcept override;

    private:
        void log(const std::string& msg, Level lvl) override;
    };

} // namespace log

#endif
