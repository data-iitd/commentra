#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    // Read the values of n and k from input

    char s[100001]; // Assuming the maximum length of s is 100000
    scanf("%s", s);
    // Read the string s from input

    int count[26] = {0};
    // Initialize a list `count` with 26 zeros to count occurrences of each letter

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'A']++;
    }
    // Iterate over each character in the string `s`, calculate its index in the `count` array, and increment the corresponding count

    // Sort the `count` array in descending order
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (count[i] < count[j]) {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
            }
        }
    }

    int res = 0;
    // Initialize `res` to 0, which will be used to store the result

    for (int i = 0; i < 26; i++) {
        if (count[i] >= k) {
            res += k * k;
            printf("%d\n", res);
            return 0;
        }
        // If the current count is greater than or equal to `k`, calculate the result using the formula `k * k` and print it, then exit the program

        k -= count[i];
        res += count[i] * count[i];
        // If the current count is less than `k`, subtract the current count from `k` and add the square of the current count to `res`
    }

    printf("%d\n", res);
    // Print the final result `res`

    return 0;
}
// <END-OF-CODE>
