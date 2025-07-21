#include <iostream>
#include <vector>
#include <algorithm>
#include "timsort.h"
using namespace std;

int minrun(int n) {
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void insertion_sort(vector<int>& arr, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) { //#1. 1, 5, 4(j), 3    #2. 1, 5(j), 4, 4      #3. 1(j), 5, 5, 4    #4 1, 3, 5, 4
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> left_part(arr.begin() + start, arr.begin() + mid + 1);
    vector<int> right_part(arr.begin() + mid + 1, arr.begin() + end + 1);

    int i = 0, j = 0, k = start;
    while (i < left_part.size() && j < right_part.size()) {
        if (left_part[i] <= right_part[j]) {
            arr[k++] = left_part[i++];
        } else {
            arr[k++] = right_part[j++];
        }
    }
    while (i < left_part.size()) arr[k++] = left_part[i++];
    while (j < right_part.size()) arr[k++] = right_part[j++];
}

void timsort(vector<int>& arr) {
    int n = arr.size();
    int mr = minrun(n);

    for (int i = 0; i < n; i += mr) {
        int end = min(i + mr - 1, n - 1);
        insertion_sort(arr, i, end);
    }

    for (int size = mr; size < n; size *= 2) {
        for (int start = 0; start < n; start += 2 * size) {
            int mid = start + size - 1;
            int end = min(start + 2 * size - 1, n - 1);

            if (mid < end) {
                merge(arr, start, mid, end);
            }
        }
    }
}