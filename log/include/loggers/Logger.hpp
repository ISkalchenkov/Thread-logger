//
// Created by antarctica on 30.07.2021.
//

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <memory>

#include "BaseLogger.hpp"

namespace log {

    using BaseLoggerPtr = std::shared_ptr<BaseLogger>;

    class Logger {
    public:
        static Logger& get_instance();

        [[nodiscard]] BaseLoggerPtr get_global_logger() const noexcept;
        void set_global_logger(BaseLoggerPtr logger);

    private:
        BaseLoggerPtr global_logger_;

        Logger();
        ~Logger() noexcept = default;
    };

    void init(BaseLoggerPtr logger);

    void debug(const std::string& msg);
    void info(const std::string& msg);
    void warning(const std::string& msg);
    void error(const std::string& msg);
    void fatal(const std::string& msg);

    void flush();

} // namespace log

#endif // LOGGER_HPP
