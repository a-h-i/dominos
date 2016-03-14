
list(APPEND SRCS board.cpp)
list(APPEND SRCS main_window.cpp)
list(APPEND SRCS dominos_app.cpp)
list(APPEND SRCS player.cpp)
list(APPEND SRCS game.cpp)
list(APPEND SRCS card_button.cpp)

# list(APPEND TEST_SRCS test/test.cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

include_directories(".")

add_executable(${EXECUTABLE_NAME} ${SRCS} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} ${wxWidgets_LIBRARIES})
#
# add_executable(${TEST_EXEC_NAME} ${SRCS}  ${TEST_SRCS} )
# target_link_libraries(${TEST_EXEC_NAME} ${wxWidgets_LIBRARIES})
