#include<stdio.h>
#include<stdlib.h>

int main(){
    int *arr;
    int size;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    // Allocate memory dynamically
    arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory Allocation failed \n");
        return -1;
    }
    
    // Input elements
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Display elements
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free allocated memory
    free(arr);
    
    return 0;
}
