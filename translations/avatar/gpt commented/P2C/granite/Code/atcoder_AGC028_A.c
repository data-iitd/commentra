
#include <stdio.h>
#include <math.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char S[N];
    scanf("%s", S);

    char T[M];
    scanf("%s", T);

    int Number_i[N];
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }

    int Number_iMN[N];
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (int) (i * M / N);
    }

    int Number_j[M];
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    int Kaburi_j[M];
    int Kaburi_Size = 0;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (Number_iMN[i] == Number_j[j]) {
                Kaburi_j[Kaburi_Size] = j;
                Kaburi_Size++;
                break;
            }
        }
    }

    int Kaburi_i[Kaburi_Size];
    for (int i = 0; i < Kaburi_Size; i++) {
        Kaburi_i[i] = (int) (Kaburi_j[i] * N / M);
    }

    int counter = 0;
    int Flag = 0;
    while (counter <= Kaburi_Size - 1) {
        if (S[Kaburi_i[counter]] == T[Kaburi_j[counter]]) {
            counter++;
        } else {
            Flag = 1;
            break;
        }
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    if (Flag == 1) {
        printf("-1\n");
    } else {
        printf("%d\n", (int) (N * M / gcd(N, M)));
    }

    return 0;
}
