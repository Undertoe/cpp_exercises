set(LIB_NAME "Chapter2")


file(GLOB SRC "*.cc")
list(REMOVE_ITEM SRC ${CMAKE_CURRENT_SOURCE_DIR}/test.cc)

message(STATUS "trimmed source:\t${SRC}")

add_library(${LIB_NAME} SHARED 
    ${SRC})

add_executable(${LIB_NAME}_test test.cc)
target_link_libraries(${LIB_NAME}_test ${LIB_NAME} pthread Catch2::Catch2WithMain)
