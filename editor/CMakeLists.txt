cmake_minimum_required(VERSION 3.20)

project(llvld_editor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(editor
    index.cpp
    element/text_element.cpp
    element/image_element.cpp
    persistence/save_to_file.cpp
    persistence/save_to_db.cpp
    model/document.cpp
)

target_include_directories(editor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    C:/msys64/ucrt64/include
)

target_link_libraries(editor PRIVATE
    C:/msys64/ucrt64/lib/libsqlite3.dll.a
)
