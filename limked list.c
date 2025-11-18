#include <stdio.h>
#include <stdlib.h>   // malloc needs this

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *n1, *n2, *n3;  // Correct pointer declaration

    // Allocate memory for nodes
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));

    // Check memory allocation
    if (n1 == NULL || n2 == NULL || n3 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print pointer values and their addresses
    printf("n1 = %p\n", n1);
    printf("Address of n1 pointer variable = %p\n", (void *)&n1);

    printf("n2 = %p\n", n2);
    printf("Address of n2 pointer variable = %p\n", (void *)&n2);

    printf("n3 = %p\n", n3);
    printf("Address of n3 pointer variable = %p\n", (void *)&n3);

    // Linking the nodes
    head = n1;

    n1->data = 1;
    n1->next = n2;

    n2->data = 11;
    n2->next = n3;

    n3->data = 12;
    n3->next = NULL;

    // Display linked list
    struct node *temp = head;
    printf("\nLinked List Output:\n");
    while (temp != NULL) {
        printf("Data: %d | Address: %p | Next: %p\n",
               temp->data, temp, temp->next);
        temp = temp->next;
    }

    return 0;
}
