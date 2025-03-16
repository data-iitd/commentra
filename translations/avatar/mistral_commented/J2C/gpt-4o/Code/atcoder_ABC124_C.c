#include <stdio.h>
#include <string.h>

void solve(const char *x) {
    int length = strlen(x);
    char a[length + 1];
    char b[length + 1];
    strcpy(a, x);
    strcpy(b, x);
    
    int a1 = 0; // Counter for number of consecutive '1's in string 'a'
    int a2 = 0; // Counter for number of consecutive '1's in string 'b'

    // Loop through each character in string 'a' starting from index 1
    for (int i = 1; i < length; i++) {
        if (a[i] == a[i - 1]) { // Check if current character is same as previous character
            if (a[i] == '1') a[i] = '0'; // If '1', change it to '0'
            else a[i] = '1'; // If not '1', change it to '1'
            a1++; // Increment counter for number of consecutive '1's
        }
    }

    // Loop through each character in string 'b' starting from the last character
    for (int i = length - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) { // Check if current character is same as previous character
            if (b[i - 1] == '1') b[i - 1] = '0'; // If '1', change it to '0'
            else b[i - 1] = '1'; // If not '1', change it to '1'
            a2++; // Increment counter for number of consecutive '1's
        }
    }

    // Print the minimum number of consecutive '1's in strings 'a' and 'b'
    printf("%d\n", (a1 < a2) ? a1 : a2);
}

int main() {
    char x[100001]; // Assuming the maximum length of the input string is 100000
    scanf("%s", x); // Read the input string
    solve(x); // Solve the problem
    return 0; // Return success
}

// <END-OF-CODE>
