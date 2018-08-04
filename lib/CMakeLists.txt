########################################################################
# Setup executable
########################################################################

set(CMAKE_CXX_FLAGS "-O3 -std=c++11 -fopenmp")

 
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/ldpc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/ldpc_encoder.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/ldpc_decoder.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/encode_example.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_83.cc
    )
 

add_executable(test_encoder ${SOURCES})

set_target_properties(test_encoder PROPERTIES LINKER_LANGUAGE CXX)

if(GSL_FOUND)
  include_directories(${GSL_INCLUDE_DIRS})
  link_directories(${GSL_LIBRARY_DIRS})
  list(APPEND test_encoder_libs ${GSL_LIBRARIES})

endif(GSL_FOUND)

target_link_libraries(test_encoder ${test_encoder_libs})
