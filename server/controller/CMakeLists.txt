add_library(controller STATIC src/basketcreator.cpp)
target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(controller model)
add_dependencies(controller model)