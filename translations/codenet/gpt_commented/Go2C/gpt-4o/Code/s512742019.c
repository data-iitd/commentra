#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

#define MOD 1000000007
=======
#include <string.h>

#define MOD (1000000000 + 7)
>>>>>>> 98c87cb78a (data updated)
#define INF (1LL << 60)

typedef struct {
    int x, h;
} Mon;

typedef struct {
    Mon *arr;
    int size;
    int capacity;
} Mons;

typedef struct {
    int x, h;
} Node;

typedef struct {
    Node *arr;
    int size;
    int capacity;
} Queue;

<<<<<<< HEAD
// Function to initialize a dynamic array for Mons
=======
// Function to initialize a Mons structure
>>>>>>> 98c87cb78a (data updated)
Mons createMons(int capacity) {
    Mons mons;
    mons.arr = (Mon *)malloc(capacity * sizeof(Mon));
    mons.size = 0;
    mons.capacity = capacity;
    return mons;
}

<<<<<<< HEAD
// Function to add a monster to the Mons array
void addMon(Mons *mons, Mon m) {
=======
// Function to add a monster to the Mons structure
void pushMon(Mons *mons, Mon m) {
>>>>>>> 98c87cb78a (data updated)
    if (mons->size == mons->capacity) {
        mons->capacity *= 2;
        mons->arr = (Mon *)realloc(mons->arr, mons->capacity * sizeof(Mon));
    }
    mons->arr[mons->size++] = m;
}

<<<<<<< HEAD
// Function to initialize a queue
=======
// Function to compare two monsters for sorting
int compareMon(const void *a, const void *b) {
    return ((Mon *)a)->x - ((Mon *)b)->x;
}

// Function to initialize a Queue structure
>>>>>>> 98c87cb78a (data updated)
Queue createQueue(int capacity) {
    Queue q;
    q.arr = (Node *)malloc(capacity * sizeof(Node));
    q.size = 0;
    q.capacity = capacity;
    return q;
}

<<<<<<< HEAD
// Function to push a Node to the queue
=======
// Function to push a Node to the Queue
>>>>>>> 98c87cb78a (data updated)
void push(Queue *q, Node v) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->arr = (Node *)realloc(q->arr, q->capacity * sizeof(Node));
    }
    q->arr[q->size++] = v;
}

<<<<<<< HEAD
// Function to get the first Node in the queue
=======
// Function to get the first Node in the Queue
>>>>>>> 98c87cb78a (data updated)
Node first(Queue *q) {
    return q->arr[0];
}

<<<<<<< HEAD
// Function to pop a Node from the queue
Node pop(Queue *q) {
    Node res = q->arr[0];
    for (int i = 1; i < q->size; i++) {
        q->arr[i - 1] = q->arr[i];
    }
=======
// Function to pop the first Node from the Queue
Node pop(Queue *q) {
    Node res = q->arr[0];
    memmove(q->arr, q->arr + 1, (q->size - 1) * sizeof(Node));
>>>>>>> 98c87cb78a (data updated)
    q->size--;
    return res;
}

<<<<<<< HEAD
// Function to check if the queue is empty
=======
// Function to check if the Queue is empty
>>>>>>> 98c87cb78a (data updated)
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Function to calculate the ceiling of a/b
int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);
    
    Mons M = createMons(N);
    for (int i = 0; i < N; i++) {
        Mon m;
        scanf("%d %d", &m.x, &m.h);
<<<<<<< HEAD
        addMon(&M, m);
    }

    // Sort monsters by their position
    for (int i = 0; i < M.size - 1; i++) {
        for (int j = i + 1; j < M.size; j++) {
            if (M.arr[i].x > M.arr[j].x) {
                Mon temp = M.arr[i];
                M.arr[i] = M.arr[j];
                M.arr[j] = temp;
            }
        }
    }

=======
        pushMon(&M, m);
    }
    
    qsort(M.arr, M.size, sizeof(Mon), compareMon);
    
>>>>>>> 98c87cb78a (data updated)
    Queue q = createQueue(N);
    int ans = 0;
    int total = 0;

    for (int i = 0; i < M.size; i++) {
        Mon m = M.arr[i];
<<<<<<< HEAD

        // Remove monsters from the queue that are out of range
        while (!isEmpty(&q) && first(&q).x < m.x) {
            total -= pop(&q).h;
        }

        // If the total damage is less than the monster's health
=======
        
        while (!isEmpty(&q) && first(&q).x < m.x) {
            total -= pop(&q).h;
        }
        
>>>>>>> 98c87cb78a (data updated)
        if (total < m.h) {
            m.h -= total;
            int count = ceilDiv(m.h, A);
            ans += count;
            int damage = count * A;
            push(&q, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }

    printf("%d\n", ans);
<<<<<<< HEAD
    free(M.arr);
    free(q.arr);
=======
    
    // Free allocated memory
    free(M.arr);
    free(q.arr);
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
