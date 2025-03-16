#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate the sum of the first n natural numbers
    int sum_n = n * (n + 1) / 2;

    // Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
    if (sum(a) % sum_n) {
        // If not divisible, print "NO" and exit
        printf("NO\n");
        return 0;
    }

    // Calculate the average value 'k' that each element should contribute
    double k = sum(a) / (double)sum_n;

    // Append the first element of 'a' to the end of the list to facilitate circular calculations
    int a_new[n + 1];
    for (i = 0; i < n; i++) {
        a_new[i] = a[i];
    }
    a_new[n] = a[0];

    // Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
    int sum_adj = 0;
    for (i = 1; i <= n; i++) {
        int adj_value = (k - a_new[i] + a_new[i - 1]) % n;
        if (adj_value < 0) {
            adj_value += n;
        }
        sum_adj += adj_value;
    }

    if (sum_adj != 0 || sum(a_new) / n < 0) {
        // If either condition fails, print "NO"
        printf("NO\n");
    } else {
        // If both conditions are satisfied, print "YES"
        printf("YES\n");
    }

    return 0;
}
