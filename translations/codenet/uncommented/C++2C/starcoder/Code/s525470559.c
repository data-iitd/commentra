#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

struct task {
    char name[100];
    int time;
};

int main()
{
    int n, q;
    int elaps = 0;
    struct task *Q;

    scanf("%d %d", &n, &q);

    Q = (struct task *)malloc(n * sizeof(struct task));

    for(int i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time);
    }

    while(n > 0) {
        struct task p = Q[0];
        if(p.time <= q) {
            elaps += p.time;
            printf("%s %d\n", p.name, elaps);
        }
        else {
            p.time -= q;
            elaps += q;
            Q[0] = p;
        }
    }
    return 0;
}

