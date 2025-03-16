#include <stdio.h>

int main() {
    int n, L, R, QL, QR;
    scanf("%d %d %d %d %d", &n, &L, &R, &QL, &QR);

    int W[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }

    // Calculating the prefix sum of the weights
    int sum_el[n + 1];
    sum_el[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum_el[i] = W[i - 1] + sum_el[i - 1];
    }

    // Initial answer calculation based on the formula
    int answer = QR * (n - 1) + sum_el[n] * R;

    // Loop to calculate energy for each possible split point
    for (int i = 1; i <= n; i++) {
        int energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]);  // Energy calculation
        if (i > (n - i)) {  // If the left side is heavier
            energy = energy + (i - (n - i) - 1) * QL;  // Adding QL if needed
        } else if ((n - i) > i) {  // If the right side is heavier
            energy = energy + ((n - i) - i - 1) * QR;  // Adding QR if needed
        }
        if (energy < answer) {  // Updating the answer if a new minimum energy is found
            answer = energy;
        }
    }

    printf("%d\n", answer);  // Output the minimum energy

    return 0;
}
