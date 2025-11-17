#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *createNode(int x) {
    struct Node *newNode =
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
struct Node *sort(struct Node *head1,struct Node *head2)
{
    struct Node* dummy = createNode(-1);
    struct Node* curr = dummy;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if (head1 != NULL) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }
    return dummy->next;
}

void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    struct Node *head2 = createNode(1);
    head2->next = createNode(4);

    struct Node *sorted = sort(head1, head2);
    printList(sorted);
    return 0;
}
