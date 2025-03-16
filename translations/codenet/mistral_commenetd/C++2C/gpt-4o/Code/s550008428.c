#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Set {
    struct Node* head;
};

void initSet(struct Set* set) {
    set->head = NULL;
}

int contains(struct Set* set, int value) {
    struct Node* current = set->head;
    while (current != NULL) {
        if (current->value == value) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

void insert(struct Set* set, int value) {
    if (contains(set, value)) {
        return; // Already exists
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = set->head;
    set->head = newNode;
}

void freeSet(struct Set* set) {
    struct Node* current = set->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int s, x, d = 2; // Initialize variables s, x, and d with initial values

    scanf("%d", &s); // Read an integer value from the standard input and assign it to variable s
    struct Set a; // Create an empty set named a
    initSet(&a); // Initialize the set
    insert(&a, s); // Add the value of s to the set a

    while (1) { // Start an infinite loop
        if (s % 2 == 0) { // Check if s is even
            x = s / 2; // Calculate the half of s and assign it to x
            if (contains(&a, x)) { // Check if x is already in the set a
                printf("%d\n", d); // If yes, print the value of d and exit the program
                freeSet(&a); // Free the set before exiting
                return 0;
            }
            insert(&a, x); // If not, add x to the set a
        } else { // If s is odd
            x = 3 * s + 1; // Calculate 3s + 1 and assign it to x
            if (contains(&a, x)) { // Check if x is already in the set a
                printf("%d\n", d); // If yes, print the value of d and exit the program
                freeSet(&a); // Free the set before exiting
                return 0;
            }
            insert(&a, x); // If not, add x to the set a
        }
        s = x; // Update the value of s with the new value of x
        d++; // Increment the value of d for each iteration
    }

    freeSet(&a); // Free the set before exiting
    return 0; // Exit the program with a return value of 0
}

// <END-OF-CODE>
