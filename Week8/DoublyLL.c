#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DLL {
    struct Node* head;
};

void insertAtFront(struct DLL* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = newNode;
    }
    list->head = newNode;
}

void insertAtEnd(struct DLL* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;+
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    struct Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev=temp;
}

void display(struct DLL* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteFront(struct DLL* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return;
    }
    struct Node* temp = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    }
    free(temp);
    printf("Deleted from front.\n");
}

void deleteEnd(struct DLL* list) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        printf("Deleted from end.\n");
        return;
    }
    struct Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end.\n");
}

void deleteByValue(struct DLL* list, int data) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete by value.\n");
        return;
    }
    struct Node* current = list->head;
    if (current != NULL && current->data == data) {
        list->head = current->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
        free(current);
        printf("Node with value %d deleted.\n", data);
        return;
    }
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found.\n", data);
        return;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    free(current);
    printf("Node with value %d deleted.\n", data);
}
int main() {
    struct DLL list = {NULL};
    int choice, data;

    do {
        printf("\nDouble Ended Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Delete by Value\n");
        printf("6. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&list, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&list, data);
                break;
            case 3:
                deleteFront(&list);
                break;
            case 4:
                deleteEnd(&list);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(&list, data);
                break;
            case 6:
                printf("Current list: ");
                display(&list);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}

