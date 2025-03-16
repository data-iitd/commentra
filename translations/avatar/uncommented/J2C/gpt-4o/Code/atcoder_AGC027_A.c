#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int main() {
    int N;
    long long x;
    scanf("%d", &N);
    scanf("%lld", &x);
    
    long long *sweet = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &sweet[i]);
    }
    
    qsort(sweet, N, sizeof(long long), compare);
    
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (x - sweet[num] >= 0) {
            x -= sweet[num];
            num++;
        } else {
            break;
        }
    }
    
    if (num == N && x > 0) {
        num -= 1;
    }
    
    printf("%d\n", num);
    
    free(sweet);
    return 0;
}

// <END-OF-CODE>
