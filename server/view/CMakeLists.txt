include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/external)

find_package (Threads REQUIRED)

ExternalProject_Add(project_pistache
    GIT_REPOSITORY https://github.com/oktal/pistache.git
    CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

ExternalProject_Add(project_nlohmann
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}

)

add_library(pistache-imported INTERFACE)
target_include_directories(pistache-imported INTERFACE ${EXTERNAL_INSTALL_LOCATION}/include)
target_link_libraries(pistache-imported INTERFACE ${EXTERNAL_INSTALL_LOCATION}/lib/libpistache.a Threads::Threads)
add_dependencies(pistache-imported project_pistache)

add_library(nlohmann-imported INTERFACE)
target_include_directories(nlohmann-imported INTERFACE ${EXTERNAL_INSTALL_LOCATION}/include/nlohmann)
add_dependencies(nlohmann-imported project_nlohmann)

add_library(view STATIC src/rest.cpp src/view.cpp)
target_include_directories(view PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(view model controller pistache-imported nlohmann-imported)
add_dependencies(view controller model pistache-imported nlohmann-imported)
