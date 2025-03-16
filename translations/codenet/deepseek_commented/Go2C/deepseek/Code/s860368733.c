#include <stdio.h>

int main() {
    int n, m; // Declare variables to store the number of elements and comparisons
    scanf("%d %d", &n, &m); // Read the number of elements and comparisons from standard input
    int h[n]; // Create an array to store the heights of the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]); // Read the heights of the elements from standard input
    }
    int a, b; // Declare variables to store the indices of the elements being compared
    int counter[n]; // Create an array to keep track of elements that cannot be the highest
    for (int i = 0; i < n; i++) {
        counter[i] = 0; // Initialize the counter array to 0
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); // Read each comparison from standard input
        if (h[a - 1] < h[b - 1]) { // Check if the height of the first element is less than the second
            counter[a - 1] = 1; // Mark the first element as not being the highest
        } else if (h[a - 1] > h[b - 1]) { // Check if the height of the first element is greater than the second
            counter[b - 1] = 1; // Mark the second element as not being the highest
        } else if (h[a - 1] == h[b - 1]) { // Check if the heights of the two elements are equal
            counter[a - 1] = 1; // Mark both elements as not being the highest
            counter[b - 1] = 1;
        }
    }
    int count = 0; // Initialize a counter to count the number of elements that can be the highest
    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) { // Check if the element can be the highest
            count++; // Increment the counter
        }
    }
    printf("%d\n", count); // Print the number of elements that can be the highest
    return 0;
}
