#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr = (int *)calloc(5, sizeof(int));

    if (ptr == NULL)
    {
        printf("Allocation Failed \n");
        exit(0);
    }

    printf("Address : %d \n", ptr);

    // Print the array
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}