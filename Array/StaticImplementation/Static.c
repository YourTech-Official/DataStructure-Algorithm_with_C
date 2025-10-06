#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void display(int arr[], int size);
int isFull(int size);
int isEmpty(int size);

int insertBegin(int arr[], int size, int value);
int insertEnd(int arr[], int size, int value);
int insertPos(int arr[], int size, int value, int index);

int deleteBegin(int arr[], int size);
int deleteEnd(int arr[], int size);
int deletePos(int arr[], int size, int index);

int search(int arr[], int size, int key);
void sort(int arr[], int size);

int main()
{
    int arr[MAX], size = 0, choice, value, index, key;

    while (1)
    {
        printf("1. Display \n");
        printf("2. Insert at Beginning \n");
        printf("3. Insert at End \n");
        printf("4. Insert at Position \n");
        printf("5. Delete from Beginning \n");
        printf("6. Delete from End \n");
        printf("7. Delete from Position \n");
        printf("8. Sort \n");
        printf("9. Search \n");
        printf("10. Exit \n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice)
        {
        case 1:
            printf("Display Array : \n\n");
            display(arr, size);
            break;
        case 2:
            printf("Enter value to insert at Beginning : ");
            scanf("%d", &value);
            size = insertBegin(arr, size, value);

            printf("Value Inseted Successfully...\n\n");
            break;
        case 3:
            printf("Enter value to insert at End : ");
            scanf("%d", &value);
            size = insertEnd(arr, size, value);

            printf("Value Inseted Successfully...\n\n");
            break;
        case 4:
            printf("Enter position index & value to insert : ");
            scanf("%d%d", &index, &value);
            size = insertPos(arr, size, value, index);

            printf("Value Inseted Successfully...\n\n");
            break;
        case 5:
            size = deleteBegin(arr, size);
            printf("Deleted Successfully...\n\n");
            break;
        case 6:
            size = deleteEnd(arr, size);
            printf("Deleted Successfully...\n\n");
            break;
        case 7:
            printf("Enter index to delete : ");
            scanf("%d", &index);
            size = deletePos(arr, size, index);

            printf("Deleted Successfully...\n\n");
            break;
        case 8:
            sort(arr, size);
            printf("Array Sorted Successfully...\n\n");
            break;
        case 9:
            if (isEmpty(size) == 1)
            {
                return -1;
            }

            printf("Enter value to be search : ");
            scanf("%d", &key);
            int Keyindex = search(arr, size, key);

            if (Keyindex == -1)
            {
                printf("The Value %d not Found \n\n", key);
            }else{
                printf("The Value %d is found at index %d \n\n", key, Keyindex);
            }
            
            break;
        case 10:
            printf("Exiting... \n");
            exit(0);

        default:
            printf("Invalid Choice Try agian... \n");
        }
    }
    return 0;
}

void display(int arr[], int size)
{
    if (isEmpty(size) == 1)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
        if (i < size - 1)
        {
            printf("-> ");
        }
    }
    printf("\n\n");
}
int isFull(int size)
{
    if (size == MAX)
    {
        printf("Array is Full \n\n");
        return 1;
    }
    return 0;
}
int isEmpty(int size)
{
    if (size == 0)
    {
        printf("Array is Empty \n\n");
        return 1;
    }
    return 0;
}
int insertBegin(int arr[], int size, int value)
{
    if (isFull(size) == 1)
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

int insertEnd(int arr[], int size, int value)
{
    if (isFull(size) == 1)
    {
        return size;
    }

    arr[size] = value;
    return size + 1;
}

int insertPos(int arr[], int size, int value, int index)
{
    if (isFull(size) == 1)
    {
        return size;
    }

    if (index < 0 || index > size)
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

int deleteBegin(int arr[], int size)
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
int deleteEnd(int arr[], int size)
{
    if (isEmpty(size) == 1)
    {
        return size;
    }
    return size - 1;
}
int deletePos(int arr[], int size, int index)
{
    if (isEmpty(size) == 1)
    {
        return size;
    }
    if (index < 0 || index >= size)
    {
        printf("Invalid index \n");
        return size;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

void sort(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
            
        }
        if (!swapped)
        {
            break;
        }      
    }
    
}

int search(int arr[], int size, int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
        
    }
    return -1;
}