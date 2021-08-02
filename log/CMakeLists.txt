set(LOG_LIB_SRCS
        "src/loggers/BaseLogger.cpp"
        "src/loggers/FileLogger.cpp"
        "src/loggers/StdoutLogger.cpp"
        "src/loggers/StderrLogger.cpp"
        "src/loggers/Logger.cpp")

add_library(${LOG_LIB_NAME} STATIC ${LOG_LIB_SRCS})
target_include_directories(${LOG_LIB_NAME} PUBLIC include)
