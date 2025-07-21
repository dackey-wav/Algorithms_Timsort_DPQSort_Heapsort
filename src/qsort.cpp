#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dualpivot_reverse(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    if (arr[left] < arr[right]) swap(arr[left], arr[right]);

    int lp = arr[left];
    int rp = arr[right];
    int lk = left + 1;
    int rk = right - 1;
    int i = left + 1;

    while (i <= rk) {
        if (arr[i] > lp) {
            swap(arr[i], arr[lk]);
            lk++;
            i++;
        } else if (arr[i] < rp) {
            swap(arr[i], arr[rk]);
            rk--;
        } else {
            i++;
        }
    }

    lk--;
    rk++;
    swap(arr[left], arr[lk]);
    swap(arr[right], arr[rk]);

    dualpivot_reverse(arr, left, lk - 1);
    dualpivot_reverse(arr, lk + 1, rk - 1);
    dualpivot_reverse(arr, rk + 1, right);
}

void dualpivot(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);

    int lp = arr[left];
    int rp = arr[right];
    int lk = left + 1;
    int rk = right - 1;
    int i = left + 1;

    while (i <= rk) {
        if (arr[i] < lp) {
            swap(arr[i], arr[lk]);
            lk++;
            i++;
        } else if (arr[i] > rp) {
            swap(arr[i], arr[rk]);
            rk--;
        } else {
            i++;
        }
    }

    lk--;
    rk++;

    swap(arr[left], arr[lk]);
    swap(arr[right], arr[rk]);

    dualpivot(arr, left, lk - 1);
    dualpivot(arr, lk + 1, rk - 1);
    dualpivot(arr, rk + 1, right);
}

void qsort(vector<int> &arr) {
    if (arr.size() > 1) {
        dualpivot(arr, 0, arr.size() - 1);
    }
}

void qsort_reverse(vector<int>& arr) {
    if (arr.size() > 1) {
        dualpivot_reverse(arr, 0, arr.size() - 1);
    }
}