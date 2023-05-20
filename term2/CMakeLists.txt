cmake_minimum_required(VERSION 3.24)
project(labs C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 labs/lab1/main.c labs/lab1/header.h labs/lab1/functions.c)
add_executable(compressor labs/lab2/compressor/main_compressor.c labs/lab2/compressor/header.h labs/lab2/compressor/compression.c)
add_executable(decompressor labs/lab2/decompressor/main_decompressor.c labs/lab2/decompressor/header.h labs/lab2/decompressor/decompression.c)
add_executable(image_editor labs/lab3/image_editor/main.c labs/lab3/image_editor/header.h labs/lab3/image_editor/processing_options.c)
add_executable(akinator labs/lab4/akinator/main.c labs/lab4/akinator/header.h labs/lab4/akinator/functions.c)
add_executable(cache labs/lab5/main.c labs/lab5/header.h labs/lab5/functions.c)
