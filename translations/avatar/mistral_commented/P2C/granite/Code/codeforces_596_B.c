
#include <stdio.h>

int main() {
    int n, r[100000], i, ans;

    // Ask the user for the number of elements in the list
    scanf("%d", &n);

    // Ask the user to input the elements of the list separated by spaces
    for (i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    // Initialize a variable to store the answer
    ans = abs(r[0]);

    // Use a for loop to calculate the sum of the absolute differences between consecutive elements
    for (i = 1; i < n; i++) {
        ans += abs(r[i] - r[i-1]);
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
