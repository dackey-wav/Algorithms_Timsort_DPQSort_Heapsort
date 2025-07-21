#include <gtest\gtest.h>
#include "kopiec.h"

TEST(HeapsortTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    heapsort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(HeapsortTest, HandlesSingleElementArray) {
    std::vector<int> arr = {1};
    heapsort(arr);
    EXPECT_EQ(arr[0], 1);
}

TEST(HeapsortTest, HandlesSortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    heapsort(arr);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
}

TEST(HeapsortReverseTest, HandlesReverseSortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    heapsort_reverse(arr);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 4);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 2);
    EXPECT_EQ(arr[4], 1);
}

TEST(HeapsortTest, HandlesIdenticalElements) {
    std::vector<int> arr = {5, 5, 5, 5, 5};
    heapsort(arr);
    EXPECT_EQ(arr, (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(HeapsortTest, HandlesDuplicateElements) {
    std::vector<int> arr = {4, 2, 2, 4, 3};
    heapsort(arr);
    EXPECT_EQ(arr, (std::vector<int>{2, 2, 3, 4, 4}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}