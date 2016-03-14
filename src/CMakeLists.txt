
list(APPEND SRCS utils.cpp)
list(APPEND TEST_SRCS test/test.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")
find_package(Boost COMPONENTS program_options REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(".")

add_executable(${EXECUTABLE_NAME} ${SRCS} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})

add_executable(${TEST_EXEC_NAME} ${SRCS}  ${TEST_SRCS} )
target_link_libraries(${TEST_EXEC_NAME} ${Boost_LIBRARIES})
