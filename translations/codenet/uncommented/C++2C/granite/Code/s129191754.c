
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmpfunc);
    for(int i=0;i<n-1;i++){
        if(a[i] == a[i+1]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
