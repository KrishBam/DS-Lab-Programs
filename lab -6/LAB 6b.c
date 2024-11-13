#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack Operations:
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;  // Indicating an error
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

void printStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Queue Operations:
void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", value);
}

int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return -1;  // Indicating an error
    }
    struct Node* temp = *front;
    int value = temp->data;
    *front = temp->next;
    if (*front == NULL) {
        printf("Queue is empty now.\n");
    }
    free(temp);
    return value;
}

void printQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stackTop = NULL;  // Top pointer for the stack
    struct Node* queueFront = NULL;  // Front pointer for the queue
    struct Node* queueRear = NULL;   // Rear pointer for the queue
    int choice, value;

    do {
        printf("\nChoose an operation:\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Print Stack\n");
        printf("6. Print Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push to Stack
                printf("Enter value to push onto stack: ");
                scanf("%d", &value);
                push(&stackTop, value);
                break;

            case 2:  // Pop from Stack
                value = pop(&stackTop);
                if (value != -1) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;

            case 3:  // Enqueue to Queue
                printf("Enter value to enqueue into queue: ");
                scanf("%d", &value);
                enqueue(&queueFront, &queueRear, value);
                break;

            case 4:  // Dequeue from Queue
                value = dequeue(&queueFront);
                if (value != -1) {
                    printf("Dequeued %d from the queue.\n", value);
                }
                break;

            case 5:  // Print Stack
                printStack(stackTop);
                break;

            case 6:  // Print Queue
                printQueue(queueFront);
                break;

            case 7:  // Exit
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
