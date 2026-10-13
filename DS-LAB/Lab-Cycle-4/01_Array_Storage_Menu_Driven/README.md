# Lab Cycle 4 – Array Storage Representation

## Question

Develop a menu-driven program to implement the following operations on array storage representation with static and dynamic memory allocation:

i) Insert by position  
ii) Delete by position  
iii) Insert by key  
iv) Delete by key  
v) Insert by order  
vi) Search by key  
vii) Search by position  
viii) Reverse the contents.

---

## Program

The following is the complete program used in `array.c`.

```c
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
```

---

## How to Compile and Run

```powershell
gcc array.c -o array
.\array.exe
```

---

## Sample Output

```text
Choose Memory Allocation:
1. Static Memory Allocation
2. Dynamic Memory Allocation
Enter your choice: 2

Enter number of elements: 5
Enter 5 elements:
10 20 30 40 50

----- ARRAY OPERATIONS -----
1. Insert by Position
2. Delete by Position
3. Insert by Key
4. Delete by Key
5. Insert by Order
6. Search by Key
7. Search by Position
8. Reverse the Contents
9. Display
10. Exit
Enter your choice: 9
Array: 10 20 30 40 50

Enter your choice: 1
Enter position: 3
Enter value: 25
Element inserted successfully.

Enter your choice: 9
Array: 10 20 25 30 40 50

Enter your choice: 2
Enter position to delete: 4
Element deleted successfully.

Enter your choice: 9
Array: 10 20 25 40 50

Enter your choice: 3
Enter key: 25
Enter value to insert: 30
Element inserted after key 25.

Enter your choice: 9
Array: 10 20 25 30 40 50

Enter your choice: 4
Enter key to delete: 40
Key 40 deleted successfully.

Enter your choice: 9
Array: 10 20 25 30 50

Enter your choice: 5
Enter value: 35
Element inserted in ascending order.

Enter your choice: 9
Array: 10 20 25 30 35 50

Enter your choice: 6
Enter key to search: 30
Key 30 found at position 4.

Enter your choice: 7
Enter position to search: 5
Element at position 5 = 35

Enter your choice: 8
Array reversed successfully.

Enter your choice: 9
Array: 50 35 30 25 20 10

Enter your choice: 10
Program terminated.
```

---

## Important Concepts

1. **Array** – stores elements of the same data type in contiguous memory.
2. **Static memory allocation** – fixed-size array using `int staticArray[MAX]`.
3. **Dynamic memory allocation** – memory allocated at runtime.
4. **`malloc()`** – allocates memory.
5. **`realloc()`** – changes the size of allocated memory.
6. **`free()`** – releases dynamically allocated memory.
7. **Pointer** – `int *a` stores the address of an integer.
8. **Pass by address** – `&n` allows functions to modify the original `n`.
9. **Insertion by position** – elements are shifted right.
10. **Deletion by position** – elements are shifted left.
11. **Insertion by key** – inserts after the first occurrence of the key.
12. **Deletion by key** – deletes the first occurrence of the key.
13. **Insertion by order** – inserts into an already sorted array in ascending order.
14. **Search by key** – linear search.
15. **Search by position** – accesses `a[pos - 1]`.
16. **Reverse** – swaps elements from both ends toward the middle.
17. **Menu-driven program** – uses `do-while` and `switch`.

---

## Top 10 Viva Questions

### 1. What is the difference between static and dynamic memory allocation?

Static memory has a fixed size, while dynamic memory is allocated during runtime.

### 2. Why is `realloc()` used?

It changes the size of dynamically allocated memory when elements are inserted or deleted.

### 3. Why is `&n` passed to the insertion/deletion functions?

It passes the address of `n`, so the function can modify the original number of elements.

### 4. Why is `(*n)++` used?

`n` is a pointer. `*n` accesses the original element count and `++` increases it.

### 5. What happens during insertion?

Elements from the insertion position are shifted one position to the right.

### 6. What happens during deletion?

Elements after the deleted element are shifted one position to the left.

### 7. What is a key?

A key is a value used to locate an element in the array.

### 8. Why is `pos - 1` used?

The program accepts positions starting from 1, while C array indexes start from 0.

### 9. Why is `free(a)` used?

It releases dynamically allocated memory and helps prevent memory leaks.

### 10. How does reverse work?

The first element is swapped with the last, the second with the second-last, and so on until the middle is reached.

---

## Important Viva Points

- Insertion → shift **RIGHT**.
- Deletion → shift **LEFT**.
- `malloc()` → allocate memory.
- `realloc()` → resize memory.
- `free()` → release memory.
- `&n` → address of `n`.
- `*n` → value stored at the address of `n`.
- `a[pos - 1]` → element at user position `pos`.
- Insert by order assumes the existing array is sorted.
- Search by key uses linear search.
