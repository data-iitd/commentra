

#include <stdio.h>
#include <string.h>

int main() {
    int n;  // Declare an integer variable to store the threshold
    char m[1000];  // Declare a character array to store the input string
    scanf("%d", &n);  // Read an integer input representing the threshold
    scanf("%s", m);  // Read a space-separated string input and store it in the character array `m`

    int possible = 1;  // Initialize an integer variable to check if the condition is possible
    int count[26] = {0};  // Declare an array to store the count of each character in the string `m`

    // Iterate over the characters in the string `m`
    for (int i = 0; m[i]!= '\0'; i++) {
        // Convert the character to lowercase and calculate its index in the `count` array
        int index = tolower(m[i]) - 'a';
        // Increment the count of the current character in the `count` array
        count[index]++;
    }

    // Iterate over the `count` array to check if the condition is possible
    for (int i = 0; i < 26; i++) {
        // Check if the count of the current character is greater than or equal to n / 2 + 1
        if (count[i] >= n / 2 + 1) {
            possible = 0;  // Set possible to 0 if the condition is met
            break;  // Break the loop as the condition is already not possible
        }
    }

    // Print 'YES' if possible is 1, otherwise print 'NO'
    if (possible == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
