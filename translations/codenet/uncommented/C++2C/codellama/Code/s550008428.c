#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int s, x, d=2; 
    scanf("%d", &s);
    int *a = (int *)malloc(sizeof(int));
    a[0] = s;

    while(1) {
        if(s%2==0){
            x = s/2;
            if(a[0]==x) {
                printf("%d\n", d);
                return 0;
            }
            a = (int *)realloc(a, sizeof(int)*(d+1));
            a[d] = x;
        } else {
            x = 3*s + 1;
            if(a[0]==x) {
                printf("%d\n", d);
                return 0;
            }
            a = (int *)realloc(a, sizeof(int)*(d+1));
            a[d] = x;
        }
        s = x;
        d++;
    }

    printf("%d\n", d);

    return 0;
}

