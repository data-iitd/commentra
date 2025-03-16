
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);  // Reading N and K from input
    int lst[N];  // Array to store the list of integers
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);  // Reading the list of integers
    }

    int lst_p[N];  // Array to store positive numbers
    int lst_m[N];  // Array to store negative numbers
    int lst_p_count = 0;  // Counter for positive numbers
    int lst_m_count = 0;  // Counter for negative numbers

    // Separating positive and negative numbers
    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;  // Decrement K if the number is 0
        }
        if (lst[i] > 0) {
            lst_p[lst_p_count] = lst[i];  // Add positive numbers to lst_p
            lst_p_count++;
        }
        if (lst[i] < 0) {
            lst_m[lst_m_count] = lst[i];  // Add negative numbers to lst_m
            lst_m_count++;
        }
    }

    int p = 0;  // Pointer for positive numbers
    int m = 0;  // Pointer for negative numbers
    int x = 0;  // Pointer for traversing lst_p
    int y = lst_m_count - 1;  // Pointer for traversing lst_m
    int lastx = lst_p_count;  // Last index of lst_p
    int lasty = lst_m_count - 1;  // Last index of lst_m

    // Function to check the minimum possible value
    int check(int k) {
        int ans = 100000000;  // Initialize answer with a large number
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {  // Check if indices are out of bounds
                continue;
            }
            if (j == 0) {
                p = 0;  // If no positive number is chosen, p is 0
            } else {
                p = lst_p[j - 1];  // Get the (j-1)th positive number
            }
            if (k - j == 0) {
                m = 0;  // If no negative number is chosen, m is 0
            } else {
                m = lst_m[lasty - (k - j)];  // Get the (lasty - (k - j))th negative number
            }
            ans = (ans < 2 * p + abs(m)? ans : 2 * p + abs(m));  // Calculate the minimum value
            ans = (ans < p + 2 * abs(m)? ans : p + 2 * abs(m));  // Calculate the minimum value
        }
        return ans;
    }

    // Output the result of the check function with K as the argument
    printf("%d\n", check(K));  // Output the minimum possible value

    return 0;
}
