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
