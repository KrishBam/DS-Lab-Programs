#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
Node *insertAtBeginning(Node *head, int value) {
    Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to concatenate two linked lists
Node *concat(Node *head1, Node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

// Function to sort the linked list in ascending order
Node *sort(Node *head) {
    if (head == NULL) return NULL;

    Node *temp, *current;
    int t;
    current = head;
    while (current != NULL) {
        temp = head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                // Swap the data
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

// Function to reverse the linked list
Node *reverse(Node *head) {
    Node *prev = NULL, *temp, *next;
    temp = head;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

// Function to display the linked list
void displayLinkedList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;

    // Inserting elements into list1
    list1 = insertAtBeginning(list1, 1);
    list1 = insertAtBeginning(list1, 2);
    list1 = insertAtBeginning(list1, 3);

    // Inserting elements into list2
    list2 = insertAtBeginning(list2, 4);
    list2 = insertAtBeginning(list2, 5);
    list2 = insertAtBeginning(list2, 6);

    // Displaying original lists
    printf("Original Lists:\n");
    displayLinkedList(list1);
    displayLinkedList(list2);

    // Sorting the lists
    printf("\nAfter Sorting:\n");
    list1 = sort(list1);
    list2 = sort(list2);
    displayLinkedList(list1);
    displayLinkedList(list2);

    // Concatenating the lists
    printf("\nAfter Concatenation:\n");
    list1 = concat(list1, list2);
    displayLinkedList(list1);

    // Reversing the concatenated list
    printf("\nAfter Reversing:\n");
    list1 = reverse(list1);
    displayLinkedList(list1);

    return 0;
}
