#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N;
    long x;
    
    scanf("%d", &N);
    scanf("%ld", &x);
    
    long *srimeList = (long *)malloc(N * sizeof(long));
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }
    
    long **costList = (long **)malloc(N * sizeof(long *));
    for (int i = 0; i < N; i++) {
        costList[i] = (long *)malloc(N * sizeof(long));
    }
    
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[(i - castNum + N) % N]) ? 
                                    costList[i][castNum - 1] : 
                                    srimeList[(i - castNum + N) % N];
        }
    }
    
    long minResult = LONG_MAX;
    for (int i = 0; i < N; i++) {
        long sum = 0;
        for (int j = 0; j < N; j++) {
            sum += costList[j][i];
        }
        long result = i * x + sum;
        if (result < minResult) {
            minResult = result;
        }
    }
    
    printf("%ld\n", minResult);
    
    // Free allocated memory
    free(srimeList);
    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }
    free(costList);
    
    return 0;
}

// <END-OF-CODE>
