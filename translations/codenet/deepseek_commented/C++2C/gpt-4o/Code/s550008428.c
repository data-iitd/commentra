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
    if (!contains(set, value)) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = value;
        newNode->next = set->head;
        set->head = newNode;
    }
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
    int s, x, d = 2;
    scanf("%d", &s); // Read the initial number from the user
    struct Set a;
    initSet(&a);
    insert(&a, s); // Insert the initial number into the set

    while (1) { // Start an infinite loop
        if (s % 2 == 0) { // Check if the current number is even
            x = s / 2; // Halve the number
            if (contains(&a, x)) { // Check if the halved number has been encountered before
                printf("%d\n", d); // Output the current step count and terminate the program
                freeSet(&a);
                return 0;
            }
            insert(&a, x); // Insert the halved number into the set
        } else { // The current number is odd
            x = 3 * s + 1; // Triple the number and add one
            if (contains(&a, x)) { // Check if the new number has been encountered before
                printf("%d\n", d); // Output the current step count and terminate the program
                freeSet(&a);
                return 0;
            }
            insert(&a, x); // Insert the new number into the set
        }
        s = x; // Update the current number to the new number
        d++; // Increment the step count
    }

    freeSet(&a); // Free the set (this line will never be reached)
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
