########################################################################
# Project setup
########################################################################

cmake_minimum_required(VERSION 2.8.9)
project(ldpc_test)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

########################################################################
# Find build dependencies
########################################################################
find_package(OpenMP REQUIRED)
find_package(Volk REQUIRED)
find_package(MathGL REQUIRED)

########################################################################
# Setup the include and linker paths
########################################################################
include_directories(${CMAKE_SOURCE_DIR}/include
                    )
                    
########################################################################
# Add subdirectories
######################################################################## 
add_subdirectory(lib)
add_subdirectory(include)
