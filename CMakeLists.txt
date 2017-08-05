cmake_minimum_required(VERSION 3.8)
project(pbrain_Yuki)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Ceil.h constant.h Pattern.h Board.h BitGrid.h BitGrid.cpp assist_code.h Board.cpp Ceil.cpp AI.h AI.cpp Answer.h)
add_executable(pbrain_Yuki ${SOURCE_FILES})