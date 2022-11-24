cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(editor VERSION ${PROJECT_VERSION})

add_executable(editor_cli main.cpp)
add_library(editor EditorModel.cpp EditorController.cpp EditorView.cpp)
add_library(figure IFigure.cpp)

set_target_properties(editor_cli editor figure PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_include_directories(editor
        PRIVATE "${CMAKE_BINARY_DIR}"
        )
target_include_directories(figure
        PRIVATE "${CMAKE_BINARY_DIR}"
        )
target_link_libraries(editor_cli PRIVATE
        editor
        figure
        )

if (MSVC)
    target_compile_options(editor_cli PRIVATE
            /W4
            )
    target_compile_options(editor PRIVATE
            /W4
            )
    target_compile_options(figure PRIVATE
            /W4
            )
else ()
    target_compile_options(editor_cli PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(editor PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(figure PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()

install(TARGETS editor_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
