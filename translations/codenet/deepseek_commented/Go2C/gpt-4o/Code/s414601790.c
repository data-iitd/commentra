#include <stdio.h>

int main() {
    int n;          // Declare an integer variable to store the number of characters in the string
<<<<<<< HEAD
    char s[100001]; // Declare a string variable to store the input string (assuming max length)
=======
    char s[100001]; // Declare a string variable to store the input string (assuming max length of 100000)
    
>>>>>>> 98c87cb78a (data updated)
    scanf("%d %s", &n, s); // Read input values for n and s from the standard input

    int max = 0;    // Initialize max to 0, this will store the maximum value of cnt
    int cnt = 0;    // Initialize cnt to 0, this will keep track of the count of 'I' minus 'D'
    
    for (int i = 0; i < n; i++) { // Loop through each character in the string s
        if (s[i] == 'I') { // If the character is 'I'
            cnt++;        // Increment cnt
        } else {          // If the character is 'D'
            cnt--;        // Decrement cnt
        }

        if (cnt > max) { // Check if the current cnt is greater than max
            max = cnt;   // Update max to be equal to cnt
        }
    }

    printf("%d\n", max); // Print the maximum value of cnt encountered
<<<<<<< HEAD
    return 0;            // Return 0 to indicate successful completion
=======
    return 0; // Return 0 to indicate successful completion
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
