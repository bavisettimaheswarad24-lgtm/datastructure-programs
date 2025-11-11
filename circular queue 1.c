#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int is_full(void) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int is_empty(void) {
    if (front == -1) {
        printf("Queue is empty!\n");
        return 1;
    }
    return 0;
}

// Function to insert an element
void enqueue(int x) {
    if (is_full()) {
        return;
    }

    if (front == -1) {
        front = 0; // First element being inserted
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("Inserted %d successfully\n", x);
}

// Function to delete an element
int dequeue(void) {
    int x;

    if (is_empty()) {
        return -1;
    }

    x = queue[front];

    // If the queue has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("Deleted element: %d\n", x);
    return x;
}

// Function to display the queue
void display(void) {
    if (is_empty()) {
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to test
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // Queue should be full now

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
