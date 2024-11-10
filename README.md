# LIBDSA
 Libray of Custom Data Structures and Algorithm Implementations in C

## Available Data Structues and Algorithms
### Data Structures
- Dynamic Array 
- Singly Linked List
- Stack
- Queue
### Algorithms
- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort

## How to Install

### Minimum Requirements

- CMake 3.20
- GNU Make 4.4.1
- GCC 13.1.0

### Build and Installation Guide (Windows)

With admin privileges:
```
mkdir build
cd build
cmake ..
make
make install
```

## How to Use

### In your Project's CMakeLists.txt:
```
find_package(dsa REQUIRED)

target_link_libraries(<project_name> PRIVATE dsa::dsa)
```

### In you C Code:
```
#include <ds/darray.h>
#inlcude <algos/mergeSort.h>
```
