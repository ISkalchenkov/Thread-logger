//
// Created by antarctica on 06.03.2021.
//

#ifndef BASE_LOGGER_H
#define BASE_LOGGER_H

#include <string>

#include "../Level.hpp"

namespace log {

    class BaseLogger {
    public:
        BaseLogger() noexcept;
        explicit BaseLogger(Level lvl) noexcept;
        virtual ~BaseLogger() noexcept = default;

        void debug(const std::string& msg);
        void info(const std::string& msg);
        void warning(const std::string& msg);
        void error(const std::string& msg);
        void fatal(const std::string& msg);

        void set_level(const Level lvl) noexcept;
        [[nodiscard]] Level level() const noexcept;
        virtual void flush() = 0;

    private:
        virtual void log(const std::string &msg, Level lvl) = 0;

        Level level_;

    };

} // namespace log

#endif