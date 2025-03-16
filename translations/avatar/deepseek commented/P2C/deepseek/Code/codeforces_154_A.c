#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];  // Assuming the maximum length of s is 1000
    int n, ans = 0;
    scanf("%s", s);  // Reading the string s
    scanf("%d", &n);  // Reading the integer n

    for (int i = 0; i < n; i++) {
        char x[3];  // String x of length 2
        scanf("%s", x);  // Reading the string x
        int a = 0, b = 0;  // Initializing counters a and b to 0

        // Iterating over each character in the string s
        for (int j = 0; j < strlen(s); j++) {
            if (s[j] == x[0]) {  // Checking if the character matches the first character of x
                a++;  // Incrementing the count for the first character
            } else if (s[j] == x[1]) {  // Checking if the character matches the second character of x
                b++;  // Incrementing the count for the second character
            } else {  // If the character does not match any of the two
                ans += (a < b) ? a : b;  // Adding the minimum of a and b to ans
                a = 0; b = 0;  // Resetting the counters a and b to 0
            }
        }
        ans += (a < b) ? a : b;  // Adding the minimum of a and b to ans after the inner loop
    }

    printf("%d\n", ans);  // Printing the final answer
    return 0;
}
