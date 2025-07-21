#include <gtest\gtest.h>
#include "qsort.h"

TEST(QuicksortTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    qsort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(QuicksortTest, HandlesSingleElementArray) {
    std::vector<int> arr = {1};
    qsort(arr);
    EXPECT_EQ(arr[0], 1);
}

TEST(QuicksortTest, HandlesSortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    qsort(arr);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(QuicksortReverseTest, HandlesReverseSortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    qsort_reverse(arr);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 4);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 2);
    EXPECT_EQ(arr[4], 1);
}

TEST(QuicksortTest, HandlesIdenticalElements) {
    std::vector<int> arr = {5, 5, 5, 5, 5};
    qsort(arr);
    EXPECT_EQ(arr, (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(QuicksortTest, HandlesDuplicateElements) {
    std::vector<int> arr = {4, 2, 2, 4, 3};
    qsort(arr);
    EXPECT_EQ(arr, (std::vector<int>{2, 2, 3, 4, 4}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}