#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    char *S = (char *)malloc((N + 1) * sizeof(char));
    char *T = (char *)malloc((M + 1) * sizeof(char));
    
    scanf("%s", S);
    scanf("%s", T);
    
    int *Number_iMN = (int *)malloc(N * sizeof(int));
    int *Kaburi_j = (int *)malloc(M * sizeof(int));
    int *Kaburi_i = (int *)malloc(M * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (i * M) / N;
    }
    
    int Kaburi_Size = 0;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (Number_iMN[i] == j) {
                Kaburi_j[Kaburi_Size] = j;
                Kaburi_i[Kaburi_Size] = (i * N) / M;
                Kaburi_Size++;
                break; // To avoid duplicates
            }
        }
    }
    
    int Flag = 0;
    for (int counter = 0; counter < Kaburi_Size; counter++) {
        if (S[Kaburi_i[counter]] != T[Kaburi_j[counter]]) {
            Flag = 1;
            break;
        }
    }
    
    if (Flag == 1) {
        printf("-1\n");
    } else {
        printf("%d\n", (N * M) / gcd(N, M));
    }
    
    free(S);
    free(T);
    free(Number_iMN);
    free(Kaburi_j);
    free(Kaburi_i);
    
    return 0;
}

// <END-OF-CODE>
