# Sorting Algorithm Performance Analysis
This project implements and analyzes the performance of three sorting algorithms: **Timsort**, **Dual-Pivot Quick Sort**, and **Heapsort**. The goal is to provide comparison of their efficiency under various data conditions and sizes.

---

## Features

* **Algorithm Implementations:**
    * **Timsort:** A hybrid stable sorting algorithm, derived from merge sort and insertion sort, designed to perform well on many kinds of real-world data.
    * **Dual-Pivot Quick Sort:** An optimized version of Quick Sort that uses two pivots to partition the array into three parts, often exhibiting better performance than the standard single-pivot Quick Sort.
    * **Heapsort:** A comparison-based sorting algorithm that uses a binary heap data structure.

* **Extensive Performance Testing:**
    The project includes a robust testing framework to measure the sorting time of each algorithm across a range of data sizes and initial data arrangements.

    * **Data Sizes:** Measurements were taken for arrays of the following sizes:
        * 1,000
        * 10,000
        * 50,000
        * 100,000
        * 500,000
        * 1,000,000

    * **Data Scenarios:** For each data size, performance was evaluated under various data distributions:
        1.  **Random Elements:** All elements are randomly ordered.
        2.  **Partially Sorted Elements:** The first 25%, 50%, 75%, 95%, 99%, 99.7%, and 100% of elements are already sorted. This helps assess performance on nearly sorted data.
        3.  **Reverse Sorted Elements:** All elements are sorted in reverse order, representing a worst-case scenario for some algorithms.

    * **Averaged Results:** To ensure accuracy and reduce statistical noise, **100 measurements** were performed for each combination of data size and scenario, and the results were averaged.

---
