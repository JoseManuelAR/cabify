add_library(controller STATIC src/basketcreator.cpp
                              src/productcreator.cpp
                              src/amountgetter.cpp
                              src/discount2x1.cpp)                              
target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(controller model common)
add_dependencies(controller model)