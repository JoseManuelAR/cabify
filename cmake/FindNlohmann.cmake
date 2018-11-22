include(ExternalProject)

ExternalProject_Add(project_nlohmann
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.4.0
    CMAKE_ARGS -DJSON_BuildTests=OFF -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}/nlohmann
)

add_library(nlohmann-imported INTERFACE)
target_include_directories(nlohmann-imported INTERFACE ${EXTERNAL_INSTALL_LOCATION}/nlohmann/include/nlohmann)
add_dependencies(nlohmann-imported project_nlohmann)