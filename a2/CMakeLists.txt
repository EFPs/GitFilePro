cmake_minimum_required(VERSION 3.8)
project(a2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES vert_hist.c tabutil.c " unscramble.c" unscramble.c.c unscramble.c unscramble2.c unscramble2.c)
add_executable(a2 ${SOURCE_FILES})