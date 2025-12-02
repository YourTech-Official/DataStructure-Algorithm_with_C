#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} Array;

Array *initialArray()
{
    Array *arr = (Array *)malloc(sizeof(Array));
    if (arr == NULL)
    {
        printf("Allocation Failed !");
        exit(0);
    }

    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
    return arr;
}
void display(Array *arr)
{
    printf("Array : \n");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
}
void insert(Array *arr, int value)
{
    if (arr->capacity == 0)
    {
        arr->capacity = arr->size + 1;
        arr->data = (int *)malloc(arr->capacity * sizeof(int));
    }
    else if (arr->size >= arr->capacity)
    {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }

    if (arr->data == NULL)
    {
        printf("Allocation Failed !\n");
        exit(1);
    }
    arr->data[arr->size] = value;
    arr->size++;
}

void freeArray(Array *arr)
{
    free(arr->data);
    free(arr);
}
int main()
{
    Array *arr = initialArray();

    insert(arr, 10);
    insert(arr, 20);
    insert(arr, 30);

    display(arr);
    freeArray(arr);
    return 0;
}