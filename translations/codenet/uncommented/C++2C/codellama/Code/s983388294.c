#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(sizeof(int)*n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int curr=0;
    for(i=0; i<n; i++) {
        if(a[i]==curr+1) curr++;
    }
    if(curr>0) {
        printf("%d\n", n-curr);
    }
    else {
        printf("-1\n");
    }

    free(a);
    return 0;
}
