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
    scanf("%d %d", &N, &M); // Read the values of N and M

    char *S = (char *)malloc((N + 1) * sizeof(char));
    char *T = (char *)malloc((M + 1) * sizeof(char));
    
    scanf("%s", S); // Read the string S
    scanf("%s", T); // Read the string T

    int *Number_i = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }

    double *Number_iMN = (double *)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (double)i * M / N;
    }

    int *Number_j = (int *)malloc(M * sizeof(int));
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    int *Kaburi_j = (int *)malloc(M * sizeof(int));
    int Kaburi_j_size = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((int)Number_iMN[i] == Number_j[j]) {
                Kaburi_j[Kaburi_j_size++] = Number_j[j];
                break;
            }
        }
    }

    int *Kaburi_i = (int *)malloc(Kaburi_j_size * sizeof(int));
    for (int j = 0; j < Kaburi_j_size; j++) {
        Kaburi_i[j] = (int)(Kaburi_j[j] * N / M);
    }

    int Flag = 0;
    for (int counter = 0; counter < Kaburi_j_size; counter++) {
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

    // Free allocated memory
    free(S);
    free(T);
    free(Number_i);
    free(Number_iMN);
    free(Number_j);
    free(Kaburi_j);
    free(Kaburi_i);

    return 0;
}

// <END-OF-CODE>
