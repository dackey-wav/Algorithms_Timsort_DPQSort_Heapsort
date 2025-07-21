#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
#include "kopiec.h"
using namespace std;
using namespace std::chrono;

// wszystkie elementy tablicy losowe
vector<int> rand_arr(int size) {
    vector<int> arr(size);
    for (int &x : arr) {
        x = rand() % 1000000;
    }
    return arr;
}

// posortowane na n%
vector<int> part_sorted_arr(int size, double sorted_percent) {
    vector<int> arr = rand_arr(size);
    int sorted_size = static_cast<int>(size * sorted_percent);
    sort(arr.begin(), arr.begin() + sorted_size);
    return arr;
}

//posortowana na odwrót
vector<int> reverse_sorted_arr(int size) {
    vector<int> arr = rand_arr(size);
    heapsort_reverse(arr);
    return arr;
}

//czas heapsort
double measure_heapsort_time(vector<int> arr) {
    auto start = high_resolution_clock::now();
    heapsort(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

int main() {
    std::ofstream file("results\\res_heapsort.txt");
    if (!file.is_open()) {
        cerr << "Error!\n";
        return 1;
    }

    vector<int> sizes = {1000, 10000, 50000, 100000, 500000, 1000000};
    vector<double> percentages = {0.25, 0.50, 0.75, 0.95, 0.99, 0.997, 1.0};
    double heapsort_time = 0;
    file << "Nazwa\tRozmiar\tCzas(ms)" << endl;

    for(int size : sizes) {
        cout << "Rozmiar tablicy: " << size << endl;
        for(int i = 0; i < 100; ++i) {
            auto arr = rand_arr(size);
            heapsort_time += measure_heapsort_time(arr);
        }
        //uśrednienie czasu
        heapsort_time /= 100;
        file << "Losowy\t" << size << "\t" << heapsort_time << endl;
    }

    for (int size : sizes) {
        cout << "Rozmiar tablicy: " << size << endl;
        for (double percentage : percentages) {
            for (int i = 0; i < 100; ++i) {
                auto arr = part_sorted_arr(size, percentage);
                heapsort_time += measure_heapsort_time(arr);
            }
            heapsort_time /= 100;
            file << "Posortowana " <<  (percentage * 100) << " %\t" << size << "\t" << heapsort_time << endl;
        }
    }

    for(int size : sizes) {
        cout << "Rozmiar tablicy: " << size << endl;
        for(int i = 0; i < 100; ++i) {
            auto arr = reverse_sorted_arr(size);
            heapsort_time += measure_heapsort_time(arr);
        }
        heapsort_time /= 100;
        file << "Posortowana odwrotnie\t" << size << "\t" << heapsort_time << endl;

    file.close();
    return 0;
    }
}