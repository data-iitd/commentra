#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
    char name[100];
    int time;
};

int main()
{
    int n, q;
    int elaps = 0;
    struct task p;
    struct task *Q = (struct task *)malloc(sizeof(struct task) * n);

    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) {
        scanf("%s %d", p.name, &p.time);
        Q[i] = p;
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
    return 0;
}

