# Static Array Implementation Using Structure

This program demonstrates a complete static array implementation using C structures with all basic operations.

## Features

- **Insert Operations**: Beginning, End, Position
- **Delete Operations**: Beginning, End, Position  
- **Search Operations**: Linear Search, Binary Search
- **Utility Operations**: Display, Sort, Check if sorted
- **Input Validation**: Overflow/Underflow checks

## Structure Definition

```c
typedef struct {
    int data[MAX];
    int size;
} st_array;
```

## Operations Implemented

1. **Display** - Show all array elements
2. **Insert at Beginning** - Add element at start
3. **Insert at End** - Add element at end
4. **Insert at Position** - Add element at specific index
5. **Delete at Beginning** - Remove first element
6. **Delete at End** - Remove last element
7. **Delete at Position** - Remove element at specific index
8. **Sort** - Bubble sort implementation
9. **Linear Search** - Sequential search
10. **Binary Search** - Search in sorted array

## How to Run

```bash
gcc main.c -o array_program
./array_program
```

## Menu Options

```
------MENU------

1. DISPLAY 
2. INSERT AT BEGINNING 
3. INSERT AT END 
4. INSERT AT POSITION 
5. DELETE AT BEGINNING 
6. DELETE AT END 
7. DELETE AT POSITION 
8. SORT 
9. LINEAR SEARCH 
10. BINARY SEARCH 
11. EXIT 
```

## Key Features

- **Memory Efficient**: Uses structure to encapsulate data and size
- **Error Handling**: Checks for overflow, underflow, and invalid positions
- **User-friendly**: Interactive menu system with clear prompts
- **Robust**: Input validation and error messages