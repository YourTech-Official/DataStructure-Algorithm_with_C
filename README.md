# Array Data Structure Implementation in C

## Table of Contents
1. [Introduction](#introduction)
2. [Array Basics](#array-basics)
3.  [Memory Allocation](#memory-allocation)
4. [Basic Operations](#basic-operations)
5. [Implementation Examples](#implementation-examples)
6. [Advantages and Disadvantages](#advantages-and-disadvantages)

## Introduction

An **array** is one of the most fundamental data structures in computer science. It is a collection of elements of the same data type stored in contiguous memory locations.  Arrays are widely used because they provide direct access to any element using an index.

## Array Basics

### Definition
An array is a fixed-size collection of elements of the same type stored in contiguous memory. 

### Key Characteristics
- **Fixed Size**: Size is determined at compile-time or allocation-time
- **Contiguous Memory**: All elements are stored next to each other
- **Zero-Indexed**: First element is at index 0
- **Direct Access**: O(1) time complexity to access any element

### Declaration Syntax
```c
// Static array
int arr[5];  // Array of 5 integers

// With initialization
int arr[5] = {1, 2, 3, 4, 5};

// Dynamic array
int *arr = (int*)malloc(5 * sizeof(int));
```

## Memory Allocation

### Static Array Allocation
```c
#include <stdio.h>

int main() {
    int arr[5];  // Stack allocation
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    
    // Access elements
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}
```

### Dynamic Array Allocation
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    // Allocate memory dynamically
    int *arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Use array
    for (int i = 0; i < n; i++) {
        arr[i] = i * 5;
    }
    
    // Free memory
    free(arr);
    arr = NULL;
    
    return 0;
}
```

## Basic Operations

### 1. **Insertion**
Inserting an element at a specific position

```c
#include <stdio. h>

void insertElement(int arr[], int *size, int position, int value) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert new element
    arr[position] = value;
    (*size)++;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    
    insertElement(arr, &size, 2, 99);
    
    // Display array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
```

### 2.  **Deletion**
Deleting an element from a specific position

```c
#include <stdio.h>

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    
    deleteElement(arr, &size, 2);
    
    // Display array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
```

### 3. **Search**
Finding an element in the array

```c
#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    int index = linearSearch(arr, size, 30);
    
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found!\n");
    }
    
    return 0;
}
```

### 4. **Traversal**
Visiting each element in the array

```c
#include <stdio.h>

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    displayArray(arr, size);
    
    return 0;
}
```

## Implementation Examples

### Complete Array Management Program

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d\n", element, position);
}

void delete(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty!\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted from position %d\n", position);
}

int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;
    
    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2.  Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insert(arr, &size, element, position);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                delete(arr, &size, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                position = search(arr, size, element);
                if (position != -1) {
                    printf("Element found at position: %d\n", position);
                } else {
                    printf("Element not found!\n");
                }
                break;
            case 4:
                display(arr, size);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
```

## Advantages and Disadvantages

### Advantages
✅ **Fast Access**: O(1) time complexity to access any element
✅ **Memory Efficient**: No extra memory overhead for pointers
✅ **Simple to Use**: Easy to implement and understand
✅ **Cache Friendly**: Contiguous memory improves cache performance
✅ **Multidimensional**: Can create 2D and 3D arrays easily

### Disadvantages
❌ **Fixed Size**: Cannot change size after creation (in static arrays)
❌ **Wasteful**: May waste memory if not all elements are used
❌ **Insertion/Deletion**: O(n) time complexity for operations in the middle
❌ **Homogeneous**: Can only store elements of the same type
❌ **Memory Allocation**: Dynamic arrays require manual memory management

## Time Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Access    | O(1)            | -                |
| Insert    | O(n)            | O(n)             |
| Delete    | O(n)            | O(n)             |
| Search    | O(n)            | O(1)             |
| Traverse  | O(n)            | O(1)             |

## Conclusion

Arrays are fundamental data structures that form the basis for many advanced data structures. Understanding array implementation in C is crucial for every programmer.  While arrays have limitations in terms of size flexibility, their efficiency in accessing elements makes them indispensable in many applications. 
