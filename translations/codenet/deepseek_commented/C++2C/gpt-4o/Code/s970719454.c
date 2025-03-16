#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100001

// Declare arrays to store information
int here[MAX_SIZE]; // To mark the presence of elements
int dp1[MAX_SIZE]; // Dynamic programming array 1
int dp2[MAX_SIZE]; // Dynamic programming array 2

int main() {
    // Main loop to read input values
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0) break; // Break the loop if n is 0
        
        // Initialize arrays for each iteration
        for (int i = 0; i < MAX_SIZE; i++) {
            here[i] = dp1[i] = dp2[i] = 0;
        }
        
        // Flag to determine behavior based on input
        bool dpflg = false;
        
        // Read m values and mark them in 'here'
        for (int i = 0; i < m; i++) {
            int a;
            scanf("%d", &a);
            if (a == 0) dpflg = true; // Set flag if any value is 0
            here[a] = 1;
        }
        
        // Variables to store maximum lengths of sequences
        int maxi1 = 0;
        int maxi2 = 0;
        
        // Calculate maximum length of sequences in dp1
        for (int i = 1; i <= n; i++) {
            if (here[i] == 1) dp1[i] = dp1[i - 1] + 1;
            maxi1 = (dp1[i] > maxi1) ? dp1[i] : maxi1;
        }
        
        // Calculate maximum length of sequences in dp2
        for (int i = 1; i <= n; i++) {
            if (here[i] == 1) {
                dp2[i] = dp2[i - 1] + 1;
            } else {
                dp2[i] = dp1[i - 1] + 1;
            }
            maxi2 = (dp2[i] > maxi2) ? dp2[i] : maxi2;
        }
        
        // Output the result based on the value of dpflg
        if (!dpflg) {
            printf("%d\n", maxi1);
        } else {
            printf("%d\n", maxi2);
        }
    }
    return 0;
}

// <END-OF-CODE>
