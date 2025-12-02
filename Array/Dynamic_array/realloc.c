#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr = (int *)malloc(sizeof(int) * 5);

    if (ptr == NULL)
    {
        printf("Allocation Failed \n");
        exit(0);
    }

    printf("Address : %d \n", ptr);

    ptr = (int *)realloc(ptr, 10 * sizeof(int));

    printf("New Address : %d \n", ptr);

    // Populate the array
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i + 1;
    }

    // Print the array
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}