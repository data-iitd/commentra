#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>

int main()
{
    int n, q;
    int elaps = 0;
    queue<task> Q;

    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) {
        task tmp;
        scanf("%s %d", tmp.name, &tmp.time);
        Q.push(tmp);
    }

    while(!Q.empty()) {
        task p = Q.front(); Q.pop();
        if(p.time <= q) {
            elaps += p.time;
            printf("%s %d\n", p.name, elaps);
        }
        else {
            p.time -= q;
            elaps += q;
            Q.push(p);
        }
    }
    return 0;
}

