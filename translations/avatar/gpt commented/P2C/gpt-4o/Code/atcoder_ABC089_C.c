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

    // Define the target characters to count
    char march[] = {'M', 'A', 'R', 'C', 'H'};
    int march_count[5] = {0};

    // Count the occurrences of each character in the input strings
    for (int i = 0; i < N; i++) {
        char first_char = S[i][0];
        for (int j = 0; j < 5; j++) {
            if (first_char == march[j]) {
                march_count[j]++;
                break;
            }
        }
    }

    // Calculate the number of ways to choose 3 different characters from the counts
    long long ans = 0;
    for (int x = 0; x < 5; x++) {
        for (int y = x + 1; y < 5; y++) {
            for (int z = y + 1; z < 5; z++) {
                ans += (long long)march_count[x] * march_count[y] * march_count[z];
            }
        }
    }

    // Print the final answer
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
