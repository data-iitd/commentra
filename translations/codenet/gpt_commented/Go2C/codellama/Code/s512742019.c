
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Mon represents a monster with position x and health h
typedef struct {
    int x;
    int h;
} Mon;

// Mons is a slice of Mon for sorting
typedef struct {
    Mon *arr;
    int len;
} Mons;

// Node represents a position and damage
typedef struct {
    int x;
    int h;
} Node;

// Queue is a simple queue implementation for Nodes
typedef struct {
    Node *arr;
    int len;
} Queue;

// push adds a Node to the end of the queue
void push(Queue *q, Node v) {
    q->arr = realloc(q->arr, (q->len + 1) * sizeof(Node));
    q->arr[q->len++] = v;
}

// first returns the first Node in the queue without removing it
Node first(Queue *q) {
    return q->arr[0];
}

// pop removes and returns the first Node in the queue
Node pop(Queue *q) {
    Node res = q->arr[0];
    q->arr = realloc(q->arr, (q->len - 1) * sizeof(Node));
    memmove(q->arr, q->arr + 1, (q->len - 1) * sizeof(Node));
    q->len--;
    return res;
}

// isEmpty checks if the queue is empty
int isEmpty(Queue *q) {
    return q->len == 0;
}

// main function to execute the program logic
int main() {
    int N, D, A; // Read N, D, A
    scanf("%d %d %d", &N, &D, &A);
    Mon *M = malloc(N * sizeof(Mon)); // Create a slice to hold monsters
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &M[i].x, &M[i].h); // Read each monster's position and health
    }
    Mons mons = {M, N}; // Create a Mons struct to sort monsters
    qsort(mons.arr, mons.len, sizeof(Mon), (int (*)(const void *, const void *))cmp); // Sort monsters by their position

    Queue q = {NULL, 0}; // Initialize a queue to manage damage
    int ans = 0; // Variable to count the total number of attacks
    int total = 0; // Variable to track total damage dealt

    // Iterate through each monster
    for (int i = 0; i < N; i++) {
        Mon m = mons.arr[i]; // Get the current monster
        // Remove monsters from the queue that are out of range
        while (!isEmpty(&q) && q.arr[0].x < m.x) {
            total -= q.arr[0].h; // Decrease total damage by the damage of the popped monster
            pop(&q);
        }
        // If the total damage is less than the monster's health
        if (total < m.h) {
            m.h -= total; // Reduce the monster's health by total damage
            int count = ceil(m.h, A); // Calculate how many attacks are needed
            ans += count; // Increment the total attack count
            int damage = count * A; // Calculate the total damage dealt to this monster
            push(&q, (Node){m.x + 2*D, damage}); // Add the monster's damage to the queue
            total += damage; // Update the total damage
        }
    }

    printf("%d\n", ans); // Output the total number of attacks
    return 0;
}

int cmp(const void *a, const void *b) {
    return ((Mon *)a)->x - ((Mon *)b)->x;
}

// END-OF-CODE
