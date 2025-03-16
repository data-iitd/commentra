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
    int s, x, d = 2;
    scanf("%d", &s);
    struct Set a;
    initSet(&a);
    insert(&a, s);

    while (1) {
        if (s % 2 == 0) {
            x = s / 2;
            if (contains(&a, x)) {
                printf("%d\n", d);
                freeSet(&a);
                return 0;
            }
            insert(&a, x);
        } else {
            x = 3 * s + 1;
            if (contains(&a, x)) {
                printf("%d\n", d);
                freeSet(&a);
                return 0;
            }
            insert(&a, x);
        }
        s = x;
        d++;
    }

    freeSet(&a);
    return 0;
}

// <END-OF-CODE>
