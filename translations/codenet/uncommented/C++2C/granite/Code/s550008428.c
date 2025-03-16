
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int s, x, d=2; 
    scanf("%d", &s);
    bool a[s+1];
    a[s] = true;

    while(1) {
        if(s%2==0){
            x = s/2;
            if(a[x]) {
                printf("%d\n", d);
                return 0;
            }
            a[x] = true;
        } else {
            x = 3*s + 1;
            if(a[x]) {
                printf("%d\n", d);
                return 0;
            }
            a[x] = true;
        }
        s = x;
        d++;
    }

    printf("%d\n", d);

    return 0;
}

