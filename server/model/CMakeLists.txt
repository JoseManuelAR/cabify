add_library(model STATIC src/basket.cpp src/product.cpp src/amount.cpp src/memory.cpp src/stock.cpp)
target_link_libraries(model common nlohmann-imported)
target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)