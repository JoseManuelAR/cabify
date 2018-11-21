add_library(model STATIC src/basket.cpp src/product.cpp src/amount.cpp src/memory.cpp)
target_link_libraries(model nlohmann-imported)
target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)