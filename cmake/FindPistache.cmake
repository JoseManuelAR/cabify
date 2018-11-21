include(ExternalProject)

find_package (Threads REQUIRED)

ExternalProject_Add(project_pistache
    GIT_REPOSITORY https://github.com/oktal/pistache.git
    CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}/pistache
)

add_library(pistache-imported INTERFACE)
target_include_directories(pistache-imported INTERFACE ${EXTERNAL_INSTALL_LOCATION}/pistache/include)
target_link_libraries(pistache-imported INTERFACE ${EXTERNAL_INSTALL_LOCATION}/pistache/lib/libpistache.a Threads::Threads)
add_dependencies(pistache-imported project_pistache)