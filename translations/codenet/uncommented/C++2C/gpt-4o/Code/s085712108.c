/*Lucky_Glass*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 7007

struct QUEUE {
    int a, b, c, tot;
};

struct QUEUE Push;
int F[6][3] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
int Hash[MOD][100]; // Assuming a maximum of 100 elements per hash bucket
int HashCount[MOD] = {0}; // To keep track of the number of elements in each bucket

bool HASH(int n) {
    int index = n % MOD;
    for (int i = 0; i < HashCount[index]; i++) {
        if (n == Hash[index][i]) {
            return false;
        }
    }
    Hash[index][HashCount[index]++] = n;
    return true;
}

int main() {
    Push.tot = 0;
    struct QUEUE que[10000]; // Assuming a maximum queue size
    int front = 0, rear = 0;

    scanf("%d%d%d", &Push.a, &Push.b, &Push.c);
    que[rear++] = Push;

    while (front < rear) {
        struct QUEUE Fro = que[front++];
        if (Fro.a == Fro.b && Fro.b == Fro.c) {
            printf("%d\n", Fro.tot);
            return 0;
        }
        for (int i = 0; i < 6; i++) {
            Push = Fro;
            Push.tot++;
            Push.a += F[i][0];
            Push.b += F[i][1];
            Push.c += F[i][2];
            int n = Push.a * 10000 + Push.b * 100 + Push.c;
            if (!HASH(n)) continue;
            que[rear++] = Push;
        }
    }
    return 0;
}

/*<END-OF-CODE>*/
