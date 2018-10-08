########################################################################
# Setup executable
########################################################################
project(lib)

set(CMAKE_CXX_FLAGS " -Wall -O3 -std=gnu++11 -fopenmp -ffast-math")

 
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
    
    
include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(test_encoder ${SOURCES} encode_example.cc ldpc_encoder.cc)

add_executable(test_decoder ${SOURCES} decode_example.cc ldpc_decoder.cc)

add_executable(BER_example ${SOURCES} BER_example.cc ldpc_encoder.cc ldpc_decoder.cc)

add_library(wimax_ldpc_lib SHARED ${SOURCES})

set_target_properties(test_encoder PROPERTIES LINKER_LANGUAGE CXX)

if(VOLK_FOUND)
  include_directories(${VOLK_INCLUDE_DIRS})
  list(APPEND test_decoder_libs ${VOLK_LIBRARIES})
  list(APPEND test_BER_libs ${VOLK_LIBRARIES})
endif(VOLK_FOUND)

if(MathGL_FOUND)
  include_directories(${MATHGL_INCLUDE_DIRS})
  list(APPEND test_BER_libs ${MathGL_LIBRARIES})
endif(MathGL_FOUND)



target_link_libraries(test_decoder ${test_decoder_libs})
target_link_libraries(wimax_ldpc_lib ${test_decoder_libs})
target_link_libraries(BER_example ${test_BER_libs})

install(TARGETS wimax_ldpc_lib DESTINATION lib)
