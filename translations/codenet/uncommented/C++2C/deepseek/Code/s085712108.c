#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 7007

typedef struct {
    int a, b, c, tot;
} QUEUE;

int F[6][3] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

QUEUE* Hash[MOD];

int HASH(int n) {
    int index = n % MOD;
    QUEUE* current = Hash[index];
    while (current != NULL) {
        if (current->a == n / 10000 && current->b == (n / 100) % 100 && current->c == n % 100) {
            return 0;
        }
        current = current->next;
    }
    QUEUE* new_node = (QUEUE*)malloc(sizeof(QUEUE));
    new_node->a = n / 10000;
    new_node->b = (n / 100) % 100;
    new_node->c = n % 100;
    new_node->tot = 0;
    new_node->next = Hash[index];
    Hash[index] = new_node;
    return 1;
}

int main() {
    QUEUE Push;
    Push.tot = 0;
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Push.a = a;
    Push.b = b;
    Push.c = c;

    QUEUE* que = (QUEUE*)malloc(sizeof(QUEUE));
    *que = Push;
    QUEUE* front = que;
    QUEUE* rear = que;

    while (front != NULL) {
        if (front->a == front->b && front->b == front->c) {
            printf("%d\n", front->tot);
            return 0;
        }
        for (int i = 0; i < 6; i++) {
            Push = *front;
            Push.tot++;
            Push.a += F[i][0];
            Push.b += F[i][1];
            Push.c += F[i][2];
            int n = Push.a * 10000 + Push.b * 100 + Push.c;
            if (!HASH(n)) continue;
            rear->next = (QUEUE*)malloc(sizeof(QUEUE));
            rear = rear->next;
            rear->a = Push.a;
            rear->b = Push.b;
            rear->c = Push.c;
            rear->tot = Push.tot;
            rear->next = NULL;
        }
        QUEUE* temp = front;
        front = front->next;
        free(temp);
    }
    return 0;
}
