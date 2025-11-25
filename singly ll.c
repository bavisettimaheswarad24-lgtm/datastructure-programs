#include <stdio.h>
#include <stdlib.h>  // for malloc

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to add node at the front
void addFirst(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;  // point to current head
    *head = new_node;        // make new node the head
}

// Function to add node at the rear (end)
void rearAdd(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {    // if list is empty
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;   // move to last node
    }
    temp->next = new_node;   // link last node to new node
}

// Function to display list
void display(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    addFirst(&head, 10);
    addFirst(&head, 20);
    rearAdd(&head, 30);
    rearAdd(&head, 40);

    display(head);

    return 0;
}
