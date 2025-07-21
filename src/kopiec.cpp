#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void kopiec_max_to_min(vector<int> &arr, int i, int n) {
    int max = i;
    int lsyn = 2 * i + 1; //indeks lewego syna
    int psyn = 2 * i + 2; //indeks prawego syna

    if(lsyn < n && arr[lsyn] > arr[max]) max = lsyn;
    if(psyn < n && arr[psyn] > arr[max]) max = psyn;
    if(max != i) {
        swap(arr[i], arr[max]);
        kopiec_max_to_min(arr, max, n);
    }
}

void kopiec_min_to_max(vector<int> &arr, int i, int n) {
    int min = i;
    int lsyn = 2 * i + 1; //indeks lewego syna
    int psyn = 2 * i + 2; //indeks prawego syna

    if(lsyn < n && arr[lsyn] < arr[min]) min = lsyn;
    if(psyn < n && arr[psyn] < arr[min]) min = psyn;
    if(min != i) {
        swap(arr[i], arr[min]);
        kopiec_min_to_max(arr, min, n);
    }
}

void heapsort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) { //sprawdzamy własności kopca dla każdego węzłą/budujemy kopiec 
        kopiec_max_to_min(arr, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        kopiec_max_to_min(arr, 0, i);
    }
}

void heapsort_reverse(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) { //sprawdzamy własności kopca dla każdego węzłą/budujemy kopiec 
        kopiec_min_to_max(arr, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        kopiec_min_to_max(arr, 0, i);
    }
}
