file(GLOB_RECURSE SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(pimpl_ptr_example ${CMAKE_CURRENT_SOURCE_DIR}/pimpl_ptr/main.cpp
                                 ${CMAKE_CURRENT_SOURCE_DIR}/pimpl_ptr/widget.cpp)
