//
// Created by antarctica on 06.03.2021.
//

#ifndef STDOUT_LOGGER_HPP
#define STDOUT_LOGGER_HPP

#include <memory>

#include "../Level.hpp"
#include "BaseLogger.hpp"

namespace log {

    class StdoutLogger final : public BaseLogger {
    public:
        explicit StdoutLogger(Level lvl) noexcept;

        void flush() override;

    private:
        void log(const std::string& msg, Level lvl) override;
    };

    std::unique_ptr<StdoutLogger> create_stdout_logger(Level lvl);

} // namespace log

#endif // STDOUT_LOGGER_HPP
