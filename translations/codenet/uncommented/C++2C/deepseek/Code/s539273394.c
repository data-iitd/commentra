```c
#include <stdio.h>
#include <string.h>

#define MAX_PRIME 1001
#define MOD 1000000007

int kekka[2];
int prime_or_not[MAX_PRIME];
int prime_list[MAX_PRIME];
int prime_num[MAX_PRIME];
int prime_counter = 0;

void sosuubunnpu() {
    for (int i = 1; i <= 1000; ++i) {
        prime_or_not[i] = 0;
    }
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 2; j <= 1000 / i; ++j) {
            if (prime_or_not[i] == 0) {
                prime_or_not[i * j] = 1;
            }
        }
    }
    for (int i = 2; i <= 1000; ++i) {
        if (prime_or_not[i] == 0) {
            prime_list[prime_counter] = i;
            prime_counter++;
        }
    }
}

void innsuubunnkai(int N, int n) {
    int time = 0;
    while (1) {
        if (N % n == 0) {
            N = N / n;
            time++;
        } else {
            break;
        }
    }
    kekka[0] = time;
    kekka[1] = N;
}

int main() {
    sosuubunnpu();
    int N;
    scanf("%d", &N);
    int innsuu[11];
    int A[N + 1][11];
    memset(prime_num, 0, sizeof(prime_num));
    unsigned long long result = 1;
    for (int current_num = 2; current_num <= N; ++current_num) {
        kekka[1] = current_num;
        for (int i = 0; i < prime_counter; ++i) {
            innsuubunnkai(kekka[1], prime_list[i]);
            prime_num[i] += kekka[0];
        }
    }
    for (int current_num = 2; current_num <= N; ++current_num) {
        for (int i = 0; i < 11; ++i) {
            innsuu[i] += A[current_num][i];
        }
    }
    for (int i = 0; i < prime_counter; ++i) {
        result = (result * (prime_num[i] + 1)) % MOD;
    }
    printf("%llu\n", result);
    return 0;
}
