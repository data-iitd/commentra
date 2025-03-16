#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);  // Read input for n and k
    int x = 0;  // Initialize x to 0

    // Check if k is within the feasible range for placing 'L' characters
    if (k <= (n * n) / 2 || k <= (n * n) - (n * n) / 2) {
        printf("YES\n");  // Print 'YES' if k is feasible
        for (int i = 0; i < n; i++) {  // Loop through each row
            for (int j = 0; j < n; j++) {  // Loop through each column
                if (i % 2 == j % 2 && x < k) {  // Check if the cell should be 'L'
                    printf("L");  // Print 'L'
                    x++;  // Increment x
                } else {
                    printf("S");  // Print 'S' otherwise
                }
            }
            printf("\n");  // Move to the next line after each row
        }
    } else {
        printf("NO\n");  // Print 'NO' if k is not feasible
    }

    return 0;
}  // <END-OF-CODE>
