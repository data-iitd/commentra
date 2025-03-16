#include <stdio.h>

int main() {
    int N, K, d, a;
    scanf("%d %d", &N, &K);
    
    int as[N + 1]; // Array to hold counts, index 0 will be unused
    for (int i = 1; i <= N; i++) {
        as[i] = 0; // Initialize counts to 0
    }
    
    for (int i = 0; i < K; i++) {
        scanf("%d", &d);
        for (int j = 0; j < d; j++) {
            scanf("%d", &a);
            as[a]++; // Increment the count for the given index
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (as[i] == 0) {
            ans++; // Count how many indices have a count of 0
        }
    }
    
    printf("%d\n", ans); // Print the result
    return 0;
}

// <END-OF-CODE>
