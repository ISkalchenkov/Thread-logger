set(EX_THREADED_LOGGING_SRCS "threadedLogging.cpp")

add_executable(${EX_THREADED_LOGGING_NAME} ${EX_THREADED_LOGGING_SRCS})

target_link_libraries(${EX_THREADED_LOGGING_NAME} ${LOG_LIB_NAME})
