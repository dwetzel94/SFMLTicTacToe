cmake_minimum_required(VERSION 2.6)
project(sfmltictactoe)

add_executable(sfmltictactoe main.cpp)

install(TARGETS sfmltictactoe RUNTIME DESTINATION bin)
