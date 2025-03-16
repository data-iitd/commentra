#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int **ans = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        ans[i] = malloc(N * sizeof(int));
    }
    
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        
        int idx = -1;
        for (int j = 0; j < i; j++) {
            if (ans[j][i - 1] < A) {
                idx = j;
                break;
            }
        }
        
        if (idx == -1) {
            ans[i][i] = A;
        } else {
            ans[idx][i] = A;
        }
    }
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i][N - 1]!= 0) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

