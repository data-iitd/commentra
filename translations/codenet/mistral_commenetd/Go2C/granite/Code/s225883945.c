

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set stdin as the input source
    setbuf(stdin, NULL);

    // Read number of elements n and the sum of elements k from stdin
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize a slice of size n to store the input elements
    int a[n];

    // Assign a default value of 0 to the first element of the slice to avoid unused variable error
    a[0] = 0;

    // Initialize sum and answer variables
    int sum = 0, ans = 1;

    // Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
    while (sum < n) {
        // Subtract 1 from sum and add k to find the next index to check
        sum = sum - 1 + k;
        // Increment the answer variable for each iteration
        ans++;
    }

    // Print the answer
    printf("%d\n", ans);

    // End of code
    return 0;
}
