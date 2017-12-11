cmake_minimum_required(VERSION 3.8)
project(fdf)

set(CMAKE_C_STANDARD 99)
set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)
find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)
find_library(MLX mlx)

set(SOURCE_FILES srcs/main.c
        srcs/draw_line.c srcs/draw_line_antialias.c
        srcs/linear_gradient.c
        libft/get_next_line.c )

add_executable(fdf ${SOURCE_FILES})
target_link_libraries(fdf ${LIBFT} ${OPENGL} ${APPKIT} ${MLX})
include_directories(includes libft/includes)