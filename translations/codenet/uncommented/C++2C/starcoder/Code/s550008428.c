#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>

int main(){
    int s, x, d=2; 
    scanf("%d", &s);
    set<int> a;
    a.insert(s);

    while(1) {
        if(s%2==0){
            x = s/2;
            if(a.find(x)!=a.end()) {
                printf("%d\n", d);
                return 0;
            }
            a.insert(x);
        } else {
            x = 3*s + 1;
            if(a.find(x)!=a.end()) {
                printf("%d\n", d);
                return 0;
            }
            a.insert(x);
        }
        s = x;
        d++;
    }

    printf("%d\n", d);

    return 0;
}

