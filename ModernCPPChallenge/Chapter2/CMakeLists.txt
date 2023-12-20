set(LIB_NAME "Chapter2")
set(TEST_NAME ${LIB_NAME}_test)

file(GLOB SRC "*.cc")
list(REMOVE_ITEM SRC ${CMAKE_CURRENT_SOURCE_DIR}/test.cc)

message(STATUS "trimmed source:\t${SRC}")

add_library(${LIB_NAME} SHARED 
    ${SRC})

add_executable(${TEST_NAME} test.cc)
target_link_libraries(${TEST_NAME} ${LIB_NAME} pthread Catch2::Catch2WithMain)


add_test(NAME ${TEST_NAME}
        COMMAND ${TEST_NAME})