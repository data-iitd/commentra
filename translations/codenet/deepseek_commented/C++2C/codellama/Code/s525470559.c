#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
    char name[100];
    int time;
};

int main()
{
    int n, q, elaps = 0;
    struct task p;
    struct task *Q = NULL;

    scanf("%d %d", &n, &q);

    Q = (struct task *)malloc(n * sizeof(struct task));

    for(int i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time);
    }

    while(n > 0) {
        p = Q[0];
        if(p.time <= q) {
            elaps += p.time;
            printf("%s %d\n", p.name, elaps);
            n--;
            for(int i = 0; i < n; i++) {
                Q[i] = Q[i + 1];
            }
        }
        else {
            p.time -= q;
            elaps += q;
            Q[0] = p;
        }
    }
    free(Q);
    return 0;
}

