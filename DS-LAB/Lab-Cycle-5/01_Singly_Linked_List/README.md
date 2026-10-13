# Lab Cycle 5 – Singly Linked List

## Question

Develop a menu driven program to implement singly linked list with various operations such as:

i) Insertion and Deletion at front/rear  
ii) Insertion and Deletion at the specified position  
iii) Delete by Key  
iv) Search by key  
v) Create an ordered list  
vi) Reverse a list  
vii) Creating a copy of the list

---

## Program

The complete runnable program is given below. The same code is saved in `singly_linked_list.c`.

```c
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// i) Insertion at front
struct Node* insertFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (!newNode)
        return head;

    newNode->next = head;
    return newNode;
}

// i) Insertion at rear
struct Node* insertRear(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (!newNode)
        return head;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// i) Deletion at front
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

// i) Deletion at rear
struct Node* deleteRear(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return NULL;
    }

    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;

    return head;
}

// ii) Insertion at specified position (1-indexed)
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }

    if (pos == 1) {
        return insertFront(head, data);
    }

    struct Node* temp = head;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }

    struct Node* newNode = createNode(data);

    if (!newNode)
        return head;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// ii) Deletion at specified position (1-indexed)
struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return NULL;
    }

    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }

    if (pos == 1) {
        return deleteFront(head);
    }

    struct Node* temp = head;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;

    printf("Deleted element: %d\n", toDelete->data);
    free(toDelete);

    return head;
}

// iii) Delete by Key
struct Node* deleteByKey(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->data == key) {
        return deleteFront(head);
    }

    struct Node* temp = head;

    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Key %d not found in the list.\n", key);
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;

    printf("Deleted element with key: %d\n", toDelete->data);
    free(toDelete);

    return head;
}

// iv) Search by key
void searchByKey(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key %d found at position %d.\n", key, pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Key %d not found in the list.\n", key);
}

// v) Insert in ascending order to maintain/create an ordered list
struct Node* insertOrdered(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (!newNode)
        return head;

    if (head == NULL || head->data >= data) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// vi) Reverse a list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    printf("List reversed successfully.\n");
    return prev;
}

// vii) Creating a copy of the list
struct Node* copyList(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* newHead = createNode(head->data);

    if (newHead == NULL)
        return NULL;

    struct Node* currentNew = newHead;
    struct Node* currentOld = head->next;

    while (currentOld != NULL) {
        currentNew->next = createNode(currentOld->data);

        if (currentNew->next == NULL)
            return newHead;

        currentNew = currentNew->next;
        currentOld = currentOld->next;
    }

    printf("Copy of the list created successfully.\n");
    return newHead;
}

// Main function containing the menu-driven interface
int main() {
    struct Node* head = NULL;
    struct Node* copiedHead = NULL;
    int choice, data, pos, key;

    while (1) {
        printf("\n================= MENU =================\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Insert at Specified Position\n");
        printf("6. Delete at Specified Position\n");
        printf("7. Delete by Key\n");
        printf("8. Search by Key\n");
        printf("9. Create / Insert into Ordered List\n");
        printf("10. Reverse List\n");
        printf("11. Create a Copy of the List and Display It\n");
        printf("12. Display Primary List\n");
        printf("13. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                displayList(head);
                break;

            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                head = insertRear(head, data);
                displayList(head);
                break;

            case 3:
                head = deleteFront(head);
                displayList(head);
                break;

            case 4:
                head = deleteRear(head);
                displayList(head);
                break;

            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position (1-indexed): ");
                scanf("%d", &pos);
                head = insertAtPosition(head, data, pos);
                displayList(head);
                break;

            case 6:
                printf("Enter position to delete (1-indexed): ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                displayList(head);
                break;

            case 7:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                head = deleteByKey(head, key);
                displayList(head);
                break;

            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                searchByKey(head, key);
                break;

            case 9:
                printf("Enter data to insert in sorted order: ");
                scanf("%d", &data);
                head = insertOrdered(head, data);
                displayList(head);
                break;

            case 10:
                head = reverseList(head);
                displayList(head);
                break;

            case 11:
                while (copiedHead != NULL) {
                    struct Node* temp = copiedHead;
                    copiedHead = copiedHead->next;
                    free(temp);
                }

                copiedHead = copyList(head);
                printf("Copied ");
                displayList(copiedHead);
                break;

            case 12:
                displayList(head);
                break;

            case 13:
                printf("Exiting program.\n");

                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }

                while (copiedHead != NULL) {
                    struct Node* temp = copiedHead;
                    copiedHead = copiedHead->next;
                    free(temp);
                }

                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
```

---

## How to Compile and Run

```powershell
gcc singly_linked_list.c -o singly_linked_list
.\singly_linked_list.exe
```

---

## Sample Output

```text
================= MENU =================
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Insert at Specified Position
6. Delete at Specified Position
7. Delete by Key
8. Search by Key
9. Create / Insert into Ordered List
10. Reverse List
11. Create a Copy of the List and Display It
12. Display Primary List
13. Exit
Enter your choice: 1
Enter data to insert at front: 10
List elements: 10 -> NULL

Enter your choice: 2
Enter data to insert at rear: 20
List elements: 10 -> 20 -> NULL

Enter your choice: 2
Enter data to insert at rear: 30
List elements: 10 -> 20 -> 30 -> NULL

Enter your choice: 5
Enter data: 25
Enter position (1-indexed): 3
List elements: 10 -> 20 -> 25 -> 30 -> NULL

Enter your choice: 6
Enter position to delete (1-indexed): 2
Deleted element: 20
List elements: 10 -> 25 -> 30 -> NULL

Enter your choice: 7
Enter key to delete: 25
Deleted element with key: 25
List elements: 10 -> 30 -> NULL

Enter your choice: 8
Enter key to search: 30
Key 30 found at position 2.

Enter your choice: 9
Enter data to insert in sorted order: 20
List elements: 10 -> 20 -> 30 -> NULL

Enter your choice: 10
List reversed successfully.
List elements: 30 -> 20 -> 10 -> NULL

Enter your choice: 11
Copy of the list created successfully.
Copied List elements: 30 -> 20 -> 10 -> NULL

Enter your choice: 12
List elements: 30 -> 20 -> 10 -> NULL

Enter your choice: 13
Exiting program.
```

---

## Important Concepts

1. **Singly linked list** – a collection of nodes where each node contains data and a pointer to the next node.
2. **Node** – consists of `data` and `next`.
3. **Structure** – `struct Node` defines the node.
4. **Head pointer** – points to the first node.
5. **`malloc()`** – dynamically allocates memory for a new node.
6. **`free()`** – releases memory occupied by a deleted node.
7. **`NULL`** – indicates the end of the linked list.
8. **Pointer** – stores the address of another variable/node.
9. **Insertion at front** – new node becomes the new head.
10. **Insertion at rear** – traverse to the last node and attach the new node.
11. **Deletion at front** – move head to the next node and free the old head.
12. **Deletion at rear** – reach the second-last node, free the last node and set `next` to `NULL`.
13. **Insertion at position** – connect the new node between two existing nodes.
14. **Deletion at position** – bypass the node to be deleted and free it.
15. **Delete by key** – search for the key and unlink the first matching node.
16. **Search by key** – traverse the list until the key is found.
17. **Ordered list** – nodes are maintained in ascending order.
18. **Reverse** – changes the direction of all links.
19. **Copy of list** – creates separate new nodes containing the same data.
20. **Menu-driven program** – uses `while(1)` and `switch`.

---

## Top 10 Viva Questions

### 1. What is a singly linked list?

A singly linked list is a collection of nodes where each node contains data and a pointer to the next node.

### 2. What is a node?

A node contains two parts: data and a pointer to the next node.

### 3. What is the purpose of the `head` pointer?

The `head` pointer stores the address of the first node in the linked list.

### 4. Why is `malloc()` used?

`malloc()` dynamically allocates memory for a new node during runtime.

### 5. Why is `free()` used?

`free()` releases dynamically allocated memory when a node is deleted.

### 6. What does `NULL` represent?

`NULL` indicates that a pointer does not point to another node. In this program it marks the end of the list.

### 7. How is insertion at the front performed?

A new node is created, its `next` points to the current head, and the new node becomes the head.

### 8. How is a linked list reversed?

Three pointers—`prev`, `current`, and `next`—are used to reverse each link one by one.

### 9. What is the difference between an array and a linked list?

An array uses contiguous memory and normally has a fixed size, while a linked list uses dynamically allocated nodes connected through pointers.

### 10. Why does the function return `struct Node*`?

The head may change after operations such as insertion/deletion at the front or reversing the list, so the updated head pointer is returned.

---

## Important Viva Points

- Node = **data + next pointer**
- `head` = **first node**
- `NULL` = **end of list**
- `malloc()` = **allocate node memory**
- `free()` = **release node memory**
- Front insertion → **change head**
- Rear insertion → **traverse to last node**
- Front deletion → **move head**
- Position insertion → **change links**
- Position deletion → **bypass node + free**
- Key search → **traversal**
- Ordered insertion → **ascending order**
- Reverse → **change link direction**
- Copy → **create new nodes**
