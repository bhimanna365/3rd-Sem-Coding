#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void display(int a[], int n);
void insertPosition(int a[], int *n, int pos, int value);
void deletePosition(int a[], int *n, int pos);
void insertKey(int a[], int *n, int key, int value);
void deleteKey(int a[], int *n, int key);
void insertOrder(int a[], int *n, int value);
void searchKey(int a[], int n, int key);
void searchPosition(int a[], int n, int pos);
void reverseArray(int a[], int n);

int main()
{
    int choice, operation;
    int n, i;
    int pos, key, value;
    int staticArray[MAX];
    int *a = NULL;
    int *temp;

    printf("Choose Memory Allocation:\n");
    printf("1. Static Memory Allocation\n");
    printf("2. Dynamic Memory Allocation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        a = staticArray;

        printf("\nEnter number of elements (0-%d): ", MAX);
        scanf("%d", &n);

        if (n < 0 || n > MAX)
        {
            printf("Invalid number of elements!\n");
            return 0;
        }

        printf("Enter %d elements:\n", n);

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
    }
    else if (choice == 2)
    {
        printf("\nEnter number of elements: ");
        scanf("%d", &n);

        if (n < 0)
        {
            printf("Invalid number of elements!\n");
            return 0;
        }

        a = (int *)malloc((n > 0 ? n : 1) * sizeof(int));

        if (a == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter %d elements:\n", n);

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
    }
    else
    {
        printf("Invalid choice!\n");
        return 0;
    }

    do
    {
        printf("\n----- ARRAY OPERATIONS -----\n");
        printf("1. Insert by Position\n");
        printf("2. Delete by Position\n");
        printf("3. Insert by Key\n");
        printf("4. Delete by Key\n");
        printf("5. Insert by Order\n");
        printf("6. Search by Key\n");
        printf("7. Search by Position\n");
        printf("8. Reverse the Contents\n");
        printf("9. Display\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &operation);

        switch (operation)
        {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);

                printf("Enter value: ");
                scanf("%d", &value);

                if (choice == 1 && n == MAX)
                {
                    printf("Array is full!\n");
                }
                else
                {
                    if (choice == 2)
                    {
                        temp = (int *)realloc(a, (n + 1) * sizeof(int));

                        if (temp == NULL)
                        {
                            printf("Memory allocation failed!\n");
                            break;
                        }

                        a = temp;
                    }

                    insertPosition(a, &n, pos, value);
                }
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                deletePosition(a, &n, pos);

                if (choice == 2 && n > 0)
                {
                    temp = (int *)realloc(a, n * sizeof(int));

                    if (temp != NULL)
                        a = temp;
                }
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);

                printf("Enter value to insert: ");
                scanf("%d", &value);

                if (choice == 1 && n == MAX)
                {
                    printf("Array is full!\n");
                }
                else
                {
                    if (choice == 2)
                    {
                        temp = (int *)realloc(a, (n + 1) * sizeof(int));

                        if (temp == NULL)
                        {
                            printf("Memory allocation failed!\n");
                            break;
                        }

                        a = temp;
                    }

                    insertKey(a, &n, key, value);
                }
                break;

            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);

                deleteKey(a, &n, key);

                if (choice == 2 && n > 0)
                {
                    temp = (int *)realloc(a, n * sizeof(int));

                    if (temp != NULL)
                        a = temp;
                }
                break;

            case 5:
                printf("Enter value: ");
                scanf("%d", &value);

                if (choice == 1 && n == MAX)
                {
                    printf("Array is full!\n");
                }
                else
                {
                    if (choice == 2)
                    {
                        temp = (int *)realloc(a, (n + 1) * sizeof(int));

                        if (temp == NULL)
                        {
                            printf("Memory allocation failed!\n");
                            break;
                        }

                        a = temp;
                    }

                    insertOrder(a, &n, value);
                }
                break;

            case 6:
                printf("Enter key to search: ");
                scanf("%d", &key);

                searchKey(a, n, key);
                break;

            case 7:
                printf("Enter position to search: ");
                scanf("%d", &pos);

                searchPosition(a, n, pos);
                break;

            case 8:
                reverseArray(a, n);
                printf("Array reversed successfully.\n");
                break;

            case 9:
                display(a, n);
                break;

            case 10:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (operation != 10);

    if (choice == 2)
        free(a);

    return 0;
}

void display(int a[], int n)
{
    int i;

    printf("Array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void insertPosition(int a[], int *n, int pos, int value)
{
    int i;

    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    for (i = *n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

void deletePosition(int a[], int *n, int pos)
{
    int i;

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;

    printf("Element deleted successfully.\n");
}

void insertKey(int a[], int *n, int key, int value)
{
    int i;
    int position = -1;

    for (i = 0; i < *n; i++)
    {
        if (a[i] == key)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
    {
        printf("Key not found!\n");
        return;
    }

    for (i = *n; i > position + 1; i--)
        a[i] = a[i - 1];

    a[position + 1] = value;
    (*n)++;

    printf("Element inserted after key %d.\n", key);
}

void deleteKey(int a[], int *n, int key)
{
    int i;
    int position = -1;

    for (i = 0; i < *n; i++)
    {
        if (a[i] == key)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
    {
        printf("Key not found!\n");
        return;
    }

    for (i = position; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;

    printf("Key %d deleted successfully.\n", key);
}

void insertOrder(int a[], int *n, int value)
{
    int i;

    i = *n - 1;

    while (i >= 0 && a[i] > value)
    {
        a[i + 1] = a[i];
        i--;
    }

    a[i + 1] = value;
    (*n)++;

    printf("Element inserted in ascending order.\n");
}

void searchKey(int a[], int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Key %d found at position %d.\n", key, i + 1);
            return;
        }
    }

    printf("Key not found!\n");
}

void searchPosition(int a[], int n, int pos)
{
    if (pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Element at position %d = %d\n", pos, a[pos - 1]);
}

void reverseArray(int a[], int n)
{
    int i, temp;

    for (i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}
