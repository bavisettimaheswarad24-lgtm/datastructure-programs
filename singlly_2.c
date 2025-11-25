void insertAtPosition(Node **head, int value, int position) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    // Case 1: Insert at beginning (position = 1)
    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse to (position-1)th node
    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(new_node);
        return;
    }

    // Insert the new node
    new_node->next = temp->next;
    temp->next = new_node;
}
int main() {
    Node *head = NULL;

    insertAtPosition(&head, 10, 1); // List: 10
    insertAtPosition(&head, 20, 2); // List: 10 -> 20
    insertAtPosition(&head, 5, 1);  // List: 5 -> 10 -> 20
    insertAtPosition(&head, 15, 3); // List: 5 -> 10 -> 15 -> 20

    display(head);
}
