add_subdirectory(common)
add_subdirectory(model)
add_subdirectory(controller)
add_subdirectory(view)

set(SERVER_TARGET "${PROJECT_NAME}-server")
add_executable(${SERVER_TARGET} main.cpp)
target_link_libraries(${SERVER_TARGET} view)
add_dependencies(${SERVER_TARGET} view)
