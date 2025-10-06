#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct
{
    int data[MAX];
    int size;
} st_array;

int isEmpty(st_array *arr);
int isFull(st_array *arr);
void menu(st_array *arr, int choice);
void display(st_array *arr);

int insertBegin(st_array *arr, int value);
int insertEnd(st_array *arr, int value);
int insertPos(st_array *arr, int index, int value);

int deleteBegin(st_array *arr);
int deleteEnd(st_array *arr);
int deletePos(st_array *arr, int index);

void sort(st_array *arr);
int linearSearch(st_array *arr, int key);
int binarySearch(st_array *arr, int key);
int isSorted(st_array *arr);

int main()
{
    st_array arr;
    arr.size = 0;

    int choice = 0;

    while (1)
    {
        printf("\n------MENU------\n\n");
        printf("1. DISPLAY \n");
        printf("2. INSERT AT BEGINNING \n");
        printf("3. INSERT AT END \n");
        printf("4. INSERT AT POSITION \n");
        printf("5. DELETE AT BEGINNING \n");
        printf("6. DELETE AT END \n");
        printf("7. DELETE AT POSITION \n");
        printf("8. SORT \n");
        printf("9. LINEAR SEARCH \n");
        printf("10. BINARY SEARCH \n");
        printf("11. EXIT \n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        menu(&arr, choice);
    }

    return 0;
}

int isEmpty(st_array *arr)
{
    if (arr->size == 0)
    {
        printf("\nUnderflow ! \n\n");
        return 1;
    }
    return 0;
}

int isFull(st_array *arr)
{
    if (arr->size == MAX)
    {
        printf("\nOverflow ! \n\n");
        return 1;
    }
    return 0;
}

void menu(st_array *arr, int choice)
{
    int value = 0, index = 0, key = 0;
    char ch = ' ';

    switch (choice)
    {
    case 1:
        if (isEmpty(arr) == 1)
        {
            break;
        }

        printf("\nArray Elements : \n");
        display(arr);

        break;

    case 2:
        if (isFull(arr) == 1)
        {
            break;
        }
        printf("\nEnter a value to insert : ");
        scanf("%d", &value);
        insertBegin(arr, value);

        break;

    case 3:
        if (isFull(arr) == 1)
        {
            break;
        }
        printf("\nEnter a value to insert : ");
        scanf("%d", &value);
        insertEnd(arr, value);

        break;

    case 4:
        if (isFull(arr) == 1)
        {
            break;
        }
        printf("\nEnter index number and value to insert : ");
        scanf("%d", &index);
        scanf("%d", &value);
        insertPos(arr, index, value);

        break;

    case 5:
        if (isEmpty(arr) == 1)
        {
            break;
        }

        deleteBegin(arr);

        break;

    case 6:
        if (isEmpty(arr) == 1)
        {
            break;
        }

        deleteEnd(arr);

        break;

    case 7:
        if (isEmpty(arr) == 1)
        {
            break;
        }

        printf("\nEnter index number to delete : ");
        scanf("%d", &index);

        deletePos(arr, index);

        break;

    case 8:
        sort(arr);
        printf("\nSorted Successfully !\n");

        break;

    case 9:
        if (isEmpty(arr) == 1)
        {
            break;
        }
        printf("\nEnter a value to be search : ");
        scanf("%d", &key);
        int keyIndex = linearSearch(arr, key);
        if (keyIndex == -1)
        {
            printf("\nNot found ! \n");
        }
        else
        {
            printf("\n%d Found at Index %d \n", key, keyIndex);
        }

        break;

    case 10:
        if (isEmpty(arr) == 1)
        {
            break;
        }

        int isSort = isSorted(arr);
        if (isSort == 0)
        {
            printf("\nArray is Not Sorted  ! \n");

            do
            {
                printf("\nDo you Want to sort Array (Y/N) : ");
                scanf(" %c", &ch);

                if (ch == 'y' || ch == 'Y')
                {
                    sort(arr);
                    break;
                }
                else if (ch == 'n' || ch == 'N')
                {
                    break;
                }
                else
                {
                    printf("\nInvalid input \n\n");
                }
            } while (1);
        }
        printf("\nEnter value to be search : ");
        scanf("%d", &key);
        int bKeyIndex = binarySearch(arr, key);
        if (bKeyIndex == -1)
        {
            printf("\n%d is not found ! \n", key);
        }
        else
        {
            printf("\n%d is Found at %d index \n", key, bKeyIndex);
        }

        break;

    case 11:
        printf("\nExit...\n");
        exit(0);

    default:
        printf("Invalid choice try again ! \n");

        break;
    }
}

void display(st_array *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
        if (i < arr->size - 1)
        {
            printf("-> ");
        }
    }
    printf("\n\n");
}

int insertBegin(st_array *arr, int value)
{
    for (int i = arr->size; i > 0; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = value;
    arr->size++;
    printf("\nInserted %d at beginning successfully!\n", value);
    return arr->size;
}

int insertEnd(st_array *arr, int value)
{
    arr->data[arr->size] = value;
    arr->size++;
    printf("\nInserted %d at end successfully!\n", value);
    return arr->size;
}

int insertPos(st_array *arr, int index, int value)
{
    if (index < 0 || index > arr->size)
    {
        printf("\nInvalid position \n\n");
        return arr->size;
    }

    for (int i = arr->size; i > index; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = value;
    arr->size++;
    printf("\n%d Inserted at %d index successfully!\n", value, index);
    return arr->size;
}

int deleteBegin(st_array *arr)
{
    printf("\nDeleted Value : %d \n", arr->data[0]);

    for (int i = 0; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    printf("\nDeleted Successfully ! \n");
    return arr->size;
}

int deleteEnd(st_array *arr)
{
    printf("\nDeleted Value : %d \n", arr->data[arr->size - 1]);
    arr->size--;
    printf("\nDeleted Successfully ! \n");
    return arr->size;
}
int deletePos(st_array *arr, int index)
{

    if (index < 0 || index >= arr->size)
    {
        printf("\nInvalid position \n\n");
        return arr->size;
    }

    printf("\nDeleted Value : %d \n", arr->data[index]);

    for (int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;
    printf("\nDeleted Successfully ! \n");
    return arr->size;
}

void sort(st_array *arr)
{
    for (int i = 0; i < arr->size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < arr->size - i - 1; j++)
        {
            if (arr->data[j] > arr->data[j + 1])
            {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int linearSearch(st_array *arr, int key)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->data[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(st_array *arr, int key)
{

    int low = 0;
    int high = arr->size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr->data[mid] == key)
            return mid;
        else if (arr->data[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int isSorted(st_array *arr)
{
    if (arr->size <= 1)
    {
        return 1;
    }

    for (int i = 0; i < arr->size - 1; i++)
    {
        if (arr->data[i] > arr->data[i + 1])
        {
            return 0;
        }
    }
    return 1;
}