########################################################################
# Project setup
########################################################################

cmake_minimum_required(VERSION 2.8.9)
project(ldpc_test)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

########################################################################
# Find build dependencies
########################################################################

find_package(GSL)

########################################################################
# Setup the include and linker paths
########################################################################
include_directories(${CMAKE_SOURCE_DIR}/include,
                    ${GLS_INCLUDE_DIRS}
                    )
                    
########################################################################
# Add subdirectories
######################################################################## 
add_subdirectory(lib)
add_subdirectory(include)