#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
<<<<<<< HEAD
#define MAX_NAME_LENGTH 100

struct task {
    char name[MAX_NAME_LENGTH];
=======

struct task {
    char name[100];
>>>>>>> 98c87cb78a (data updated)
    int time;
};

int main() {
    int n, q;
    int elaps = 0;
    struct task Q[MAX_TASKS];
    int front = 0, rear = 0;

    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) {
        struct task tmp;
        scanf("%s %d", tmp.name, &tmp.time);
        Q[rear++] = tmp;
    }

    while(front < rear) {
        struct task p = Q[front++];
        if(p.time <= q) {
            elaps += p.time;
            printf("%s %d\n", p.name, elaps);
        } else {
            p.time -= q;
            elaps += q;
            Q[rear++] = p;
        }
    }
    return 0;
}

// <END-OF-CODE>
