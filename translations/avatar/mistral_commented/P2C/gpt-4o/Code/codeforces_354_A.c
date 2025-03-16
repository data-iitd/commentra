#include <stdio.h>

int main() {
    // Define input variables
    int n, L, R, QL, QR;
    scanf("%d %d %d %d %d", &n, &L, &R, &QL, &QR);
    
    // Read input as a list of integers
    int W[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }

    // Initialize array to store sum of elements
    long long sum_el[n + 1];
    sum_el[0] = 0;

    // Calculate sum of elements from 1 to n
    for (int i = 1; i <= n; i++) {
        sum_el[i] = W[i - 1] + sum_el[i - 1];
    }

    // Calculate initial answer
    long long answer = QR * (n - 1) + sum_el[n] * R;

    // Iterate through all elements to find minimum energy
    for (int i = 1; i <= n; i++) {
        // Calculate energy for current index
        long long energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]);
        
        // Check if current index is greater than its mirror index
        if (i > (n - i)) {
            // If true, add energy of segments between current index and its mirror index
            energy += (i - (n - i) - 1) * QL;
        }
        // Check if mirror index is greater than current index
        else if ((n - i) > i) {
            // If true, add energy of segments between mirror index and current index
            energy += ((n - i) - i - 1) * QR;
        }

        // Update answer if current energy is less than previous answer
        if (energy < answer) {
            answer = energy;
        }
    }

    // Print the answer
    printf("%lld\n", answer);

    return 0;
}

// <END-OF-CODE>
