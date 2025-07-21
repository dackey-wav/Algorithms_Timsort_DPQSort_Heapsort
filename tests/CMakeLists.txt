enable_testing()

# kopiec_test
add_executable(kopiec_test kopiec_test.cpp)
target_link_libraries(kopiec_test gtest gtest_main kopiec)
add_test(NAME kopiec_test COMMAND kopiec_test)

# timsort_test
add_executable(timsort_test timsort_test.cpp)
target_link_libraries(timsort_test gtest gtest_main timsort)
add_test(NAME timsort_test COMMAND timsort_test)

# qsort_test
add_executable(qsort_test qsort_test.cpp)
target_link_libraries(qsort_test gtest gtest_main qsort_lib)
add_test(NAME qsort_test COMMAND qsort_test)

