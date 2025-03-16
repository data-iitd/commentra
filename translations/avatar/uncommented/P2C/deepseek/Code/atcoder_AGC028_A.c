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
    char S[N+1], T[M+1];
    scanf("%s", S);
    scanf("%s", T);

    int Number_iMN[N];
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (i * M) / N;
    }

    int Number_j[M];
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    int Kaburi_j[M];
    int Kaburi_i[N];
    int counter = 0;
    int Flag = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Number_iMN[i] == Number_j[j]) {
                Kaburi_i[counter] = (j * N) / M;
                counter++;
            }
        }
    }

    for (int i = 0; i < counter; i++) {
        if (S[Kaburi_i[i]] != T[Kaburi_j[i]]) {
            Flag = 1;
            break;
        }
    }

    if (Flag == 1) {
        printf("-1\n");
    } else {
        printf("%d\n", (N * M) / gcd(N, M));
    }

    return 0;
}
