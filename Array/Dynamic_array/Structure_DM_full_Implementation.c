#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int capacity;
    int size;
} Array;
Array *initialArray()
{
    Array *arr = (Array *)malloc(sizeof(Array));
    if (arr == NULL)
    {
        printf("Alloction Failed !\n");
        exit(1);
    }

    arr->data = NULL;
    arr->capacity = 0;
    arr->size = 0;

    return arr;
}
void freeMemory(Array *arr)
{
    free(arr->data);
    free(arr);
}
int isEmpty(Array *arr)
{
    if (arr->size == 0)
    {
        printf("Can't delete, Array is empty ! \n");
        return 1;
    }
    return 0;
}
void display(Array *arr)
{
    printf("Array : \n");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}
void MemoryAllocation(Array *arr)
{
    if (arr->capacity == 0)
    {
        arr->capacity = arr->size + 1;
        arr->data = (int *)malloc(arr->capacity * sizeof(int));
        if (arr->data == NULL)
        {
            printf("Data Memory Alloction Failed ! \n");
            exit(1);
        }
    }
    else if (arr->size >= arr->capacity)
    {
        arr->capacity *= 2;
        int *temp = (int *)realloc(arr->data, arr->capacity * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory Reallocation Failed ! \n");
            freeMemory(arr);
            exit(1);
        }
        arr->data = temp;
    }
}
void insertAtBeginning(Array *arr, int value)
{
    MemoryAllocation(arr);

    for (int i = arr->size; i > 0; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = value;
    arr->size++;
}
void insertAtEnd(Array *arr, int value)
{
    MemoryAllocation(arr);
    arr->data[arr->size] = value;
    arr->size++;
}
void insertAtPosition(Array *arr, int value, int index)
{
    MemoryAllocation(arr);

    if (index < 0 || index > arr->size)
    {
        printf("Invalid Index \n");
        return;
    }

    for (int i = arr->size; i > index; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
}

void deleteAtBeginning(Array *arr)
{
    if (isEmpty(arr))
    {
        return;
    }

    for (int i = 0; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}
void deleteAtEnd(Array *arr)
{
    if (isEmpty(arr))
    {
        return;
    }
    arr->size--;
}
void deleteAtPosition(Array *arr, int index)
{
    if (isEmpty(arr))
    {
        return;
    }

    if (index < 0 || index >= arr->size)
    {
        printf("Invalid index \n");
        return;
    }

    for (int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}
int main()
{
    Array *arr = initialArray();
    printf("Initilization done");

    insertAtBeginning(arr, 1);
    insertAtBeginning(arr, 2);
    insertAtBeginning(arr, 3);
    display(arr);
    insertAtEnd(arr, 10);
    insertAtEnd(arr, 20);
    insertAtEnd(arr, 30);
    insertAtEnd(arr, 40);
    display(arr);
    insertAtPosition(arr, 5, 2);
    insertAtPosition(arr, 6, 3);
    insertAtPosition(arr, 7, 4);
    display(arr);
    deleteAtBeginning(arr);
    display(arr);
    deleteAtEnd(arr);
    display(arr);
    deleteAtPosition(arr, 4);
    display(arr);
    freeMemory(arr);
    return 0;
}
