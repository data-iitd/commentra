#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    
    char S[MAX_N][100]; // Assuming each string can be up to 99 characters long
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }

    char march[] = {'M', 'A', 'R', 'C', 'H'};
    int march_lis[5] = {0};

    // Count occurrences of characters in 'march'
    for (int i = 0; i < N; i++) {
        char first_char = S[i][0];
        for (int j = 0; j < 5; j++) {
            if (first_char == march[j]) {
                march_lis[j]++;
                break;
            }
        }
    }

    // Calculate the number of combinations of three elements from march_lis
    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += (long long)march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    // Print the final answer
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
