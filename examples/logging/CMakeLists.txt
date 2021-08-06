cmake_minimum_required(VERSION 3.15)

set(EX_LOGGING_SRCS "logging.cpp")
add_executable(${EX_LOGGING_NAME} ${EX_LOGGING_SRCS})
target_link_libraries(${EX_LOGGING_NAME} ${LOG_LIB_NAME})
