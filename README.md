# Sparse Array and Sparse Matrix using Linked Lists

## Overview
This project implements sparse data structures (1D sparse array and 2D sparse matrix) using doubly linked lists.  
Instead of storing large arrays and matrices full of zeros (wasting time and memory), this project efficiently stores only the non-zero values with their indices.

The project is divided into two main parts:

1. Sparse 1D Array (ArrayLinkedList)  
   - Stores only non-zero elements in a linked list of (index, value) pairs.  
   - Provides efficient operations such as set, get, add, and print.  

2. Sparse 2D Matrix (MatrixLinkedList)  
   - Each row is implemented as a sparse array (ArrayLinkedList).  
   - The matrix itself is a linked list of rows.  
   - Supports set, print, and add operations.  

This design saves memory and computation for very large arrays/matrices where most entries are zero.

---

## Project Structure
sparse_array.hpp     -> Implementation of Sparse Array (1D) using doubly linked list  
sparse_matrix.hpp    -> Implementation of Sparse Matrix (2D) using linked list of sparse arrays  
main.cpp             -> Example usage and test cases  

---

## Sparse 1D Array (ArrayLinkedList)

Each non-zero element is represented by an ArrayNode:

struct ArrayNode {
    int data;       // value
    int index;      // position in array
    ArrayNode* next;
    ArrayNode* prev;
};

Supported operations:
- set_value(int value, int index) → Insert or update a value at a given index.  
- get_value(int index) → Retrieve value (0 if not present).  
- add(ArrayLinkedList& other) → Add another sparse array to the current one (in-place).  
- print_array() → Print full array with zeros.  
- print_array_nonzero() → Print only non-zero values.  

Example:
ArrayLinkedList arr(10);  
arr.set_value(20, 2);  
arr.set_value(40, 4);  
arr.set_value(50, 5);  
arr.print_array();   // 0 0 20 0 40 50 0 0 0 0  

---

## Sparse 2D Matrix (MatrixLinkedList)

Each row is an ArrayLinkedList.  
The matrix is a linked list of rows:

struct MatrixNode {
    ArrayLinkedList list;   // Sparse row
    MatrixNode* next;
};

Supported operations:
- set_value(int x, int y, int value) → Set value at row y, column x.  
- print() → Print matrix row by row (including zeros).  
- add(const MatrixLinkedList& other) → Add another matrix to this one (row by row).  

Example:
MatrixLinkedList mat(5, 5);  
mat.set_value(2, 3, 10);  // Row 3, Col 2 = 10  
mat.set_value(0, 0, 7);   // Row 0, Col 0 = 7  
mat.print();  

Output:  
7 0 0 0 0  
0 0 0 0 0  
0 0 0 0 0  
0 0 10 0 0  
0 0 0 0 0  

---

## Applications
- Polynomial representation (e.g., 2x^60 + 17x^1500)  
- Large sparse matrices in scientific computing, computer vision, and AI  
- Graph adjacency representation where most edges are absent  

---

## How to Run
Create a main.cpp with:

#include "sparse_array.hpp"  
#include "sparse_matrix.hpp"  

int main() {  
    ArrayLinkedList arr(10);  
    arr.set_value(5, 3);  
    arr.print_array();  

    MatrixLinkedList mat(5, 5);  
    mat.set_value(1, 2, 9);  
    mat.print();  

    return 0;  
}  

Compile:  
g++ main.cpp -o sparse  

Run:  
./sparse  

---

## Key Features
- Memory-efficient representation of arrays and matrices  
- In-place addition of sparse arrays and matrices  
- Can print both dense view (with zeros) and sparse view (only non-zeros)  
