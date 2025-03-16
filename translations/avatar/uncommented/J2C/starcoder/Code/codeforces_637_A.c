#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ara[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
    }
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(max < ara[i]) {
            max = ara[i];
        }
    }
    int count[max+1];
    for(int i = 0; i < max+1; i++) {
        count[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        count[ara[i]]++;
    }
    int max_count = 0;
    for(int i = 0; i < max+1; i++) {
        if(max_count < count[i]) {
            max_count = count[i];
        }
    }
    for(int i = 0; i < max+1; i++) {
        if(count[i] == max_count) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

