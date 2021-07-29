//
// Created by antarctica on 06.03.2021.
//

#ifndef STDOUT_LOGGER_H
#define STDOUT_LOGGER_H

#include "../Level.hpp"
#include "BaseLogger.hpp"

namespace log {

    class StdoutLogger final : public BaseLogger {
    public:
        StdoutLogger() noexcept = default;
        explicit StdoutLogger(Level lvl) noexcept;

        void flush() noexcept override;

    private:
        void log(const std::string& msg, Level lvl) override;
    };

} // namespace log

#endif
