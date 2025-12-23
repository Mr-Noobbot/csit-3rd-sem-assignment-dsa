#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


int isFull() {
    return (front == (rear + 1) % MAX);
}


int isEmpty() {
    return (front == -1);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = 0; // first element
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    if (front == rear) {
        // Queue has become empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
