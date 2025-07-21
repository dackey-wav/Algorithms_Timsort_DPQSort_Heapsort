#include <gtest/gtest.h>
#include "timsort.h"

TEST(TimsortTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    timsort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(TimsortTest, HandlesSingleElementArray) {
    std::vector<int> arr = {1};
    timsort(arr);
    EXPECT_EQ(arr[0], 1);
}

TEST(TimsortTest, HandlesSortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    timsort(arr);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(TimsortTest, HandlesReverseSortedArray) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    timsort(arr);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(TimsortTest, HandlesIdenticalElements) {
    std::vector<int> arr = {5, 5, 5, 5, 5};
    timsort(arr);
    EXPECT_EQ(arr, (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(TimsortTest, HandlesDuplicateElements) {
    std::vector<int> arr = {4, 2, 2, 4, 3};
    timsort(arr);
    EXPECT_EQ(arr, (std::vector<int>{2, 2, 3, 4, 4}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}