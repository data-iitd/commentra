#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100001];
    long long rc = 0, gc = 0, bc = 0;
    long long result;

    // Read the integer n which represents the length of the string
    scanf("%d", &n);

    // Read the string s which contains characters 'R', 'G', and 'B'
    scanf("%s", s);

    // Count the occurrences of each character in the string
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            rc++; // Increment red counter
        } else if (s[i] == 'G') {
            gc++; // Increment green counter
        } else {
            bc++; // Increment blue counter
        }
    }

    // Calculate the initial result based on the product of the counts
    result = rc * gc * bc;

    // Iterate through all pairs of indices (i, k) to check conditions
    for (int i = 1; i <= n; i++) {
        for (int k = i + 1; k <= n; k++) {
            // Check if the sum of indices is even
            if ((i + k) % 2 == 0) {
                int j = (i + k) / 2;
                // Get the characters at the current indices
                char is = s[i - 1];
                char ks = s[k - 1];
                char js = s[j - 1];

                // Check if all three characters are different
                if (is != ks && ks != js && js != is) {
                    result--; // Decrease the result if the condition is met
                }
            }
        }
    }

    // Output the final result
    printf("%lld\n", result);

    return 0;
}
