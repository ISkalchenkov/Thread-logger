cmake_minimum_required(VERSION 3.15)

set(THREADED_LOGGER_SRCS "threaded_logger.cpp")
add_executable(threaded_logger ${THREADED_LOGGER_SRCS})
target_link_libraries(threaded_logger ${LOG_LIB_NAME})
