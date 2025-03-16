#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000 // Assuming a maximum size for the array

typedef struct {
    long *data;
    int front;
    int rear;
    int size;
    int capacity;
} LinkedList;

// Function to create a LinkedList
LinkedList* createLinkedList(int capacity) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->capacity = capacity;
    list->front = 0;
    list->rear = -1;
    list->size = 0;
    list->data = (long *)malloc(capacity * sizeof(long));
    return list;
}

// Function to add an element to the LinkedList
void add(LinkedList *list, long value) {
    if (list->size < list->capacity) {
        list->rear = (list->rear + 1) % list->capacity;
        list->data[list->rear] = value;
        list->size++;
    }
}

// Function to remove the first element from the LinkedList
void pollFirst(LinkedList *list) {
    if (list->size > 0) {
        list->front = (list->front + 1) % list->capacity;
        list->size--;
    }
}

// Function to get the first element from the LinkedList
long getFirst(LinkedList *list) {
    if (list->size > 0) {
        return list->data[list->front];
    }
    return -1; // Return -1 if the list is empty
}

// Function to get the last element from the LinkedList
long getLast(LinkedList *list) {
    if (list->size > 0) {
        return list->data[list->rear];
    }
    return -1; // Return -1 if the list is empty
}

// Function to check if the LinkedList is empty
int isEmpty(LinkedList *list) {
    return list->size == 0;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b); // Reading n and b
    long ans[MAX_N]; // Array to store answers
    LinkedList *q = createLinkedList(n); // Creating a LinkedList

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d); // Reading t and d

        // Remove elements from the queue that are less than or equal to t
        while (!isEmpty(q) && getFirst(q) <= t) {
            pollFirst(q);
        }

        // Check if the size of the queue is less than or equal to b
        if (q->size <= b) {
            ans[i] = (isEmpty(q) ? t : getLast(q)) + d; // Calculate the answer
            add(q, ans[i]); // Add the answer to the queue
        } else {
            ans[i] = -1; // Set answer to -1 if the condition is false
        }
    }

    // Print the answers
    for (int i = 0; i < n; ++i) {
        printf("%ld ", ans[i]); // Printing the answer for the current test case
    }

    // Free allocated memory
    free(q->data);
    free(q);

    return 0;
}

// <END-OF-CODE>
