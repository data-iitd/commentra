
#include <stdio.h>

// Define a recursive function 'aaa' that takes a string 'n'
int aaa(char *n) {
    // Check if the integer value of 'n' exceeds the limit N
    if (atoi(n) > N) {
        return 0;  // If it does, return 0 (base case)
    }

    // Check if the digits of 'n' are exactly '7', '5', and '3'
    int ans = 1;
    for (int i = 0; n[i]!= '\0'; i++) {
        if (n[i]!= '7' && n[i]!= '5' && n[i]!= '3') {
            ans = 0;
            break;
        }
    }

    // Iterate over each character in the string '753'
    char digits[] = "753";
    for (int i = 0; digits[i]!= '\0'; i++) {
        // Create a new string by concatenating 'n' and 'digits[i]'
        char new_n[100];
        strcpy(new_n, n);
        strcat(new_n, &digits[i]);

        // Recursively call 'aaa' with the new string 'new_n'
        ans += aaa(new_n);
    }

    // Return the accumulated answer
    return ans;
}

int main() {
    // Read an integer input from the user
    scanf("%d", &N);

    // Call 'aaa' with the initial value '0' and print the result
    printf("%d\n", aaa("0"));

    return 0;
}
