add_library(kopiec STATIC kopiec.cpp)
target_include_directories(kopiec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(qsort_lib STATIC qsort.cpp)
target_include_directories(qsort_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(timsort STATIC timsort.cpp)
target_include_directories(timsort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
