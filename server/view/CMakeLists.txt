add_library(view STATIC src/rest.cpp src/view.cpp)
target_include_directories(view PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(view model controller pistache-imported nlohmann-imported)
add_dependencies(view controller model pistache-imported nlohmann-imported)
