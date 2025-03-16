
#include <stdio.h>

int main() {
    int n;  // Read the number of elements in the list
    scanf("%d", &n);

    int l[n];  // Declare an array of size n to store the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);  // Read n elements and store them in the array l
    }

    int ans = n - 1;  // Initialize ans to n - 1, which will store the final answer
    int last = 0;  // Initialize last to 0, used to track the last element in the list

    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;  // Update ans based on the current element and last element
        last = l[i];  // Update last to the current element
    }

    printf("%d\n", ans);  // Print the final answer

    return 0;
}
