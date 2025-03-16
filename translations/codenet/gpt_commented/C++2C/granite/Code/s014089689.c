
#include<stdio.h>

int main() {
    // Declare an integer variable to store the length of the string
    int n;
    // Read the length of the string from user input
    scanf("%d", &n);

    // Declare a string variable to store the input string
    char s[n];
    // Read the string from user input
    scanf("%s", s);

    // Initialize a counter to count the number of distinct segments
    int cnt = 0;

    // Iterate through each character in the string
    for (int i = 0; i < n; i++) {
        // Increment the counter for each new segment found
        cnt++;

        // Initialize a variable j to find the end of the current segment
        int j = i + 1;

        // Continue moving j forward as long as the characters are the same
        for (; j < n; j++) {
            // If the current character is different from the next character, break the loop
            if (s[i]!= s[j]) {
                break;
            }
        }

        // Move i to the end of the current segment
        i = j - 1;
    }

    // Output the total count of distinct segments
    printf("%d\n", cnt);

    return 0; // Indicate that the program ended successfully
}
