########################################################################
# Setup executable
########################################################################

set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++11 -fopenmp")

 
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/ldpc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_83.cc
    )
 

add_executable(test_encoder ${SOURCES} encode_example.cc ldpc_encoder.cc)
add_executable(test_decoder ${SOURCES} decode_example.cc ldpc_decoder.cc)

set_target_properties(test_encoder PROPERTIES LINKER_LANGUAGE CXX)

if(GSL_FOUND)
  include_directories(${GSL_INCLUDE_DIRS})
  link_directories(${GSL_LIBRARY_DIRS})
  list(APPEND test_encoder_libs ${GSL_LIBRARIES})

endif(GSL_FOUND)

target_link_libraries(test_encoder ${test_encoder_libs})
