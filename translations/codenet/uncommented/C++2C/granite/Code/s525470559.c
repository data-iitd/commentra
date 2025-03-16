
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct task {
    char name[100];
    int time;
} task;

int main()
{
    int n, q;
    int elaps = 0;
    struct task *Q = NULL;

    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) {
        struct task *tmp = (struct task *)malloc(sizeof(struct task));
        scanf("%s %d", tmp->name, &tmp->time);
        tmp->next = Q;
        Q = tmp;
    }

    while(Q!= NULL) {
        struct task *p = Q;
        Q = Q->next;
        if(p->time <= q) {
            elaps += p->time;
            printf("%s %d\n", p->name, elaps);
            free(p);
        }
        else {
            p->time -= q;
            elaps += q;
            p->next = Q;
            Q = p;
        }
    }
    return 0;
}

