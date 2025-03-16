#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100

int main() {
    int N;
    scanf("%d", &N);
    
    char S[MAX_N][100]; // Assuming each string can be up to 99 characters + null terminator
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }

    int march_lis[5] = {0}; // M, A, R, C, H
    char march[5] = {'M', 'A', 'R', 'C', 'H'};

    for (int i = 0; i < N; i++) {
        char first_char = S[i][0];
        for (int j = 0; j < 5; j++) {
            if (first_char == march[j]) {
                march_lis[j]++;
                break;
            }
        }
    }

    long long ans = 0;
    for (int x = 0; x < 5; x++) {
        for (int y = x + 1; y < 5; y++) {
            for (int z = y + 1; z < 5; z++) {
                ans += (long long)march_lis[x] * march_lis[y] * march_lis[z];
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
