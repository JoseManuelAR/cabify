add_library(model STATIC src/basket.cpp src/product.cpp src/memory.cpp)
target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)