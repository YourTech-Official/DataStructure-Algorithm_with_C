#include <stdio.h>
#include <stdlib.h>

int *initialize(int size);
int isFull(int capacity, int size);
void freeMemory(int *arr);
int isEmpty(int size);
void display(int *arr, int size);

int insertBegin(int *arr, int size, int capacity, int value);
int insertend(int *arr, int size, int capacity, int value);
int insertPos(int *arr, int size, int capacity, int index, int value);

int deleteBegin(int *arr, int size);
int deleteEnd(int *arr, int size);
int deletePos(int *arr, int size, int index);

void sort(int *arr, int size);
int linear(int *arr, int size, int key);
int binSearch(int *arr, int size, int key);

int *initialize(int size)
{

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("MEMORY ALLOCATION FAILED ! \n");
        exit(0);
    }

    return arr;
}
int isFull(int capacity, int size)
{
    if (size >= capacity)
    {
        printf("OVERFLOW \n");
        return 1;
    }
    return 0;
}
void freeMemory(int *arr)
{

    free(arr);
}
int isEmpty(int size)
{
    if (size == 0)
    {
        printf("UNDERFLOW \n");
        return 1;
    }
    return 0;
}

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
        if (i < size - 1)
        {
            printf("-> ");
        }
    }
    printf("\n");
}

int insertBegin(int *arr, int size, int capacity, int value)
{
    if (isFull(capacity, size) == 1)
    {
        return size;
    }

    for (int i = size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;

    return size + 1;
}

int insertend(int *arr, int size, int capacity, int value)
{
    if (isFull(capacity, size) == 1)
    {
        return size;
    }

    arr[size] = value;

    return size + 1;
}

int insertPos(int *arr, int size, int capacity, int index, int value)
{
    if (isFull(capacity, size) == 1)
    {
        return size;
    }

    if (index<0 | index> size)
    {
        printf("Invalid Index \n");
        return size;
    }

    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;

    return size + 1;
}

int deleteBegin(int *arr, int size)
{
    if (isEmpty(size) == 1)
    {
        return size;
    }
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int deleteEnd(int *arr, int size)
{
    if (isEmpty(size) == 1)
    {
        return size;
    }

    return size - 1;
}

int deletePos(int *arr, int size, int index)
{
    if (isEmpty(size) == 1)
    {
        return size;
    }

    if (index < 0 || index > size)
    {
        return size;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

void sort(int *arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linear(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return 0;
}

int binSearch(int *arr, int size, int key)
{
    int first = 0;
    int last = size - 1;

    while (first <= last)
    {

        int mid = (first + last) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
}

int main()
{
    int *arr, capacity, size = 0;

    printf("Enter the size of array : ");
    scanf("%d", &capacity);

    arr = initialize(capacity);

    printf("Inserted at Bginning...\n");
    size = insertBegin(arr, size, capacity, 20);
    display(arr, size);

    printf("Inserted at Ending...\n");
    size = insertend(arr, size, capacity, 30);
    display(arr, size);

    printf("Inserted at given postion...\n");
    size = insertPos(arr, size, capacity, 1, 40);
    size = insertPos(arr, size, capacity, 1, 50);
    size = insertPos(arr, size, capacity, 1, 10);
    display(arr, size);

    int ind = linear(arr, size, 20);
    printf("linear search index : %d \n", ind);

    printf("Sorting... \n");
    sort(arr, size);
    display(arr, size);

    int index = binSearch(arr, size, 30);
    printf("Binary search index : %d \n", index);

    printf("Deleted at Beginning... \n");
    size = deleteBegin(arr, size);
    display(arr, size);
    
    printf("Deleted at Ending... \n");
    size = deleteEnd(arr, size);
    display(arr, size);
    
    printf("Deleted at given position... \n");
    size = deletePos(arr, size, 1);
    display(arr, size);

    freeMemory(arr);
    arr = NULL;

    return 0;
}