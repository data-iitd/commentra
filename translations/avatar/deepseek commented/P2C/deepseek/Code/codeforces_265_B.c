#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements in the list
    int l[n];  // Declare an array to store the elements

    // Read n elements and store them in the array l
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    int ans = n - 1;  // Initialize ans to n - 1, which will store the final answer
    int last = 0;  // Initialize last to 0, used to track the last element in the list

    // Iterate over each element in the array l
    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;  // Update ans based on the current element and last element
        last = l[i];  // Update last to the current element
    }

    printf("%d\n", ans);  // Print the final answer

    return 0;
}
