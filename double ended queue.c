#include <stdio.h>
#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

/* check full */
int is_full(void) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
        return 1;
    }
    return 0;
}

/* check empty */
int is_empty(void) {
    if (front == -1) {
        printf("Queue is empty!\n");
        return 1;
    }
    return 0;
}

/* insert at rear (same as enqueue) */
void insert_rear(int x) {
    if (is_full()) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    dq[rear] = x;
    printf("Inserted %d at rear\n", x);
}

/* insert at front */
void insert_front(int x) {
    if (is_full()) return;
    if (front == -1) {         /* first element */
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    dq[front] = x;
    printf("Inserted %d at front\n", x);
}

/* delete from front */
int delete_front(void) {
    int x;
    if (is_empty()) return -1;
    x = dq[front];
    if (front == rear) {      /* single element */
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("Deleted element from front: %d\n", x);
    return x;
}

/* delete from rear */
int delete_rear(void) {
    int x;
    if (is_empty()) return -1;
    x = dq[rear];
    if (front == rear) {      /* single element */
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
    printf("Deleted element from rear: %d\n", x);
    return x;
}

/* display */
void display(void) {
    if (is_empty()) return;
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

/* main to test */
int main(void) {
    /* use insert_rear to mimic enqueue(10..50) */
    insert_rear(10);
    insert_rear(20);
    insert_rear(30);
    insert_rear(40);
    insert_rear(50); /* should print full when next insertion attempted */

    display();

    delete_front();
    delete_front();

    display();

    /* demonstrate insert at front and rear on available slots */
    insert_front(60); /* insert at front */
    insert_rear(70);  /* insert at rear */

    display();

    /* extra: delete from rear to show symmetry */
    delete_rear();
    display();

    return 0;
}
