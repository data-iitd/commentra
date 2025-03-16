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
    
    char S[1000], T[1000];
    scanf("%s", S);
    scanf("%s", T);
    
    int list_S[1000], list_T[1000];
    for (int i = 0; i < N; i++) {
        list_S[i] = S[i];
    }
    for (int i = 0; i < M; i++) {
        list_T[i] = T[i];
    }
    
    int Number_i[1000];
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }
    
    int Number_iMN[1000];
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (Number_i[i] * M) / N;
    }
    
    int Number_j[1000];
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }
    
    int Kaburi_j[1000];
    int Kaburi_i[1000];
    int counter = 0;
    int Flag = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Number_iMN[i] == Number_j[j]) {
                Kaburi_j[counter] = j;
                Kaburi_i[counter] = (Number_j[j] * N) / M;
                counter++;
                break;
            }
        }
    }
    
    for (int i = 0; i < counter; i++) {
        if (list_S[Kaburi_i[i]] != list_T[Kaburi_j[i]]) {
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
