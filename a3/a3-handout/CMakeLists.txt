cmake_minimum_required(VERSION 3.8)
project(a3_handout)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        box/box.c
        box/box.h
        box/Makefile
        box/test.in
        btree/btree.c
        btree/btree.h
        btree/Makefile
        det/det.c
        det/det.in
        det/Makefile
        mergesort/Makefile
        mergesort/mergesort.c
        mergesort/mergesort.h
        mergesort/test.in
        queue/Makefile
        queue/queue.c
        queue/queue.h)

add_executable(a3_handout ${SOURCE_FILES})