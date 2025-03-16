
#include <stdio.h>
#include <string.h>

int main() {
    // Read two integers n and k from input
    int n, k;
    scanf("%d %d", &n, &k);

    // Read the string s from input
    char s[n];
    scanf("%s", s);

    // Initialize a list to count occurrences of each letter (A-Z)
    int count[26] = {0};

    // Count the occurrences of each character in the string
    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }

    // Sort the count list in descending order to prioritize higher counts
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (count[i] < count[j]) {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
            }
        }
    }

    // Initialize the result variable to accumulate the final score
    int res = 0;

    // Iterate through the sorted count list
    for (int i = 0; i < 26; i++) {
        // If the current count is greater than or equal to k
        if (count[i] >= k) {
            // Add k squared to the result and print it
            res += k * k;
            printf("%d\n", res);
            return 0;  // Exit the program since we have found the result
        }

        // Decrease k by the current count
        k -= count[i];

        // Add the square of the current count to the result
        res += count[i] * count[i];
    }

    // Print the final result after processing all counts
    printf("%d\n", res);

    return 0;
}
