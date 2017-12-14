cmake_minimum_required(VERSION 3.8)
project(fdf)

add_custom_target(fdf ALL COMMAND make -C ${fdf_SOURCE_DIR} fclean
                        CLION_EXE_DIR=${PROJECT_BINARY_DIR})