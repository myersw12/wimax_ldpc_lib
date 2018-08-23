########################################################################
# Setup executable
########################################################################

set(CMAKE_CXX_FLAGS " -Wall -O3 -std=c++11 -fopenmp")

 
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/ldpc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_576_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_672_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_672_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_672_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_672_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_672_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_672_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_768_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_768_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_768_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_768_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_768_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_768_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_864_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_864_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_864_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_864_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_864_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_864_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_960_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_960_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_960_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_960_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_960_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_960_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1056_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1056_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1056_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1056_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1056_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1056_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1152_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1152_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1152_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1152_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1152_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1152_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1248_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1248_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1248_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1248_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1248_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1248_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1344_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1344_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1344_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1344_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1344_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1344_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1440_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1440_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1440_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1440_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1440_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1440_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1536_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1536_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1536_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1536_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1536_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1536_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1632_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1632_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1632_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1632_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1632_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1632_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1728_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1728_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1728_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1728_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1728_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1728_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1824_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1824_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1824_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1824_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1824_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1824_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1920_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1920_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1920_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1920_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1920_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_1920_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2016_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2016_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2016_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2016_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2016_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2016_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2112_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2112_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2112_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2112_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2112_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2112_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2208_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2208_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2208_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2208_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2208_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2208_0_83.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2304_0_5.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2304_0_66A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2304_0_66B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2304_0_75A.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2304_0_75B.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/matrices/wimax_2304_0_83.cc
    )
 

add_executable(test_encoder ${SOURCES} encode_example.cc ldpc_encoder.cc)
add_executable(test_decoder ${SOURCES} decode_example.cc ldpc_decoder.cc)

add_library(wimax_ldpc_lib ${SOURCES})

set_target_properties(test_encoder PROPERTIES LINKER_LANGUAGE CXX)

if(GSL_FOUND)
  include_directories(${GSL_INCLUDE_DIRS})
  link_directories(${GSL_LIBRARY_DIRS})
  list(APPEND test_encoder_libs ${GSL_LIBRARIES})

endif(GSL_FOUND)

target_link_libraries(test_encoder ${test_encoder_libs})
target_link_libraries(wimax_ldpc_lib ${test_encoder_libs})
