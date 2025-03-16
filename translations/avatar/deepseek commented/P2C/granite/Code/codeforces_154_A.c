
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];  // Declaring a character array s of maximum length 100001
    int n;  // Declaring an integer variable n
    scanf("%s", s);  // Taking input string s
    scanf("%d", &n);  // Taking integer input n

    int ans = 0;  // Initializing the answer variable to 0

    for (int i = 0; i < n; i++) {
        char x[3];  // Declaring a character array x of length 3
        scanf("%s", x);  // Taking input for string x of length 2
        int a = 0, b = 0;  // Initializing counters a and b to 0

        for (int j = 0; j < strlen(s); j++) {
            if (s[j] == x[0]) {  // Checking if the character matches the first character of x
                a++;  // Incrementing the count for the first character
            } else if (s[j] == x[1]) {  // Checking if the character matches the second character of x
                b++;  // Incrementing the count for the second character
            } else {  // If the character does not match any of the two
                ans += (a < b? a : b);  // Adding the minimum of a and b to ans
                a = b = 0;  // Resetting the counters a and b to 0
            }
        }

        ans += (a < b? a : b);  // Adding the minimum of a and b to ans after the inner loop
    }

    printf("%d", ans);  // Printing the final answer

    return 0;
}
// END-OF-CODE