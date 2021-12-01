# Abstract Sorting

This project involves implementing custom forward and random-access iterators for 3 containers: Vector, List, Dictionary/AVLTree, as well as implementing find, Insertion Sort, Quicksort, and Heapsort algorithms that take iterator ranges as arguments. The performance of  the three sorting algorithms will be examined using a variety of dataset sizes and configurations.

### Build and Execution
Using an Ubuntu terminal:  
```
cd /mnt/c/[path to project directory]  
mkdir build  
cd build  
cmake ..
cmake --build .
./AbstractSorting
```

## Data Set Generation
Creation of data sets is handled by two sets of functions (one for integer data, one for string data) that will generate values and place them in certain configurations; these include ascending, descending, and randomized data as well as data with either 20% or 40% duplicate values.


The data set sizes chosen for my project are: {1000, 10000, 100000, 150000, 200000, 250000}. While higher values would be ideal for demonstrating worst-case time complexity, the runtimes become unreasonably long on my machine.

### Random Data
Random integer data sets were generated using
```cpp
std::shuffle(), std::mt19937(std::random_device())
```
by creating ascending data sets and shuffling them using a random seed.  
  
Random string data sets were generated using
```cpp
std::random_device device,  std::mt19937 generator(device()), std::uniform_int_distribution<int> distribution();
```
by creating random integer data sets with a distribution containing only 10-digit integers, and then converting them to strings.

### Sorting Algorithm Verification
The sorting algorithms were run individually with all 6 data set sizes and all 5 data configurations for both integer and string data to ensure that they correctly and completely sort the data.

## Data Analysis
The following data was collected from testing the sorting algorithms with different data set sizes and configurations:

![Ascending Data](/graphs/AscendingData.png)
![Descending Data](/graphs/DescendingData.png)
![Random Data](/graphs/RandomData.png)
![20% Duplicate Data](/graphs/D20Data.png)
![40% Duplicate Data](/graphs/D40Data.png)

### Insertion Sort
From the data collected, insertion sort clearly seems to perform best when the data set is either nearly sorted or already sorted in ascending order. This is the only case in which it performs quicker on all input sizes compared to the other two algorithms. Given that insertion sort is not a divide-and-conquer algorithm, its runtime increases greatly as data set size grows beyond small values. It performs comparably with Quicksort and Heapsort for all data configurations until the set size reaches about 100,000. Insertion sort performs much slower when the data set is in descending order, which is where it approaches its worst-case complexity of O(n^2).

### Quicksort
Quicksort appears to perform similarly on most input configurations, although the data suggests that it may be particularly fast at sorting sets with duplicate values. Its performance on both the 20% and 40% duplicate data sets were marginally better than on ascending, descending or randomized data (specifically for input sizes greater than 10,000). While the data collected shows that it performed poorly on sets sorted in ascending order, this is likely due to the pivot being placed at the beginning of the set. Placing it closer to the average would yield better performance. However, Quicksort noticeably outperforms insertion sort on all data configurations except ascending.

### Heapsort
Heapsort tremendously outperformed the other two algorithms on all data configurations except ascending order (where insertion sort performs slightly better). Although it has a best-case time complexity of O(n logn) just like Quicksort, Heapsort avoids the performance decay to O(n^2) that Quicksort undergoes at higher input sizes by repeatedly arranging the set in heap order. As such, it maintains its O(n logn) complexity and its performance is comparatively better than that of insertion sort and Quicksort. Despite this, Heapsort does seem to perform slightly better on sets with duplicate values as well.

### String Data
While it is clear that sorting string data increased runtime of all 3 algorithms regardless of configuration, the data shows that insertion sort's runtime increases much more drastically for all configurations except ascending order. This increase in runtime is also more severe for larger input sizes for all 3 algorithms, with smaller input sizes having similar runtimes to integer data. Lastly, the impact of changing from integer to string data is much less pronounced in Heapsort's runtimes; while the other algorithms have their runtimes increased by factors of 5 or 6, Heapsort doesn't exceed even a second of runtime in all of the data collected.
