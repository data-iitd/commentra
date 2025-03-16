#include <stdio.h> // Including standard input-output library

int main() { // Starting the main function
    int n; // Variable to store the length of the string
    scanf("%d", &n); // Reading the first integer input from the console
    char s[n + 1]; // Declaring a character array to store the string (with an extra space for null terminator)
    scanf("%s", s); // Reading the second string input from the console

    long rc = 0; // Initializing the count for 'R' characters to zero
    long gc = 0; // Initializing the count for 'G' characters to zero
    long bc = 0; // Initializing the count for other characters to zero

    for (int i = 0; i < n; i++) { // Starting a loop to iterate through each character in the string
        if (s[i] == 'R') { // Checking if the current character is 'R'
            rc++; // Incrementing the count for 'R' characters
        } else if (s[i] == 'G') { // Checking if the current character is 'G'
            gc++; // Incrementing the count for 'G' characters
        } else { // If the current character is not 'R' or 'G'
            bc++; // Incrementing the count for other characters
        }
    }

    long result = rc * gc * bc; // Multiplying the counts of 'R', 'G' and other characters to get the initial result

    for (int i = 1; i <= n; i++) { // Starting a loop to iterate through each pair of indices in the string
        for (int k = i + 1; k <= n; k++) { // Starting a nested loop to iterate through each pair of indices that are not too far apart
            if ((i + k) % 2 == 0) { // Checking if the sum of the indices is even
                char is = s[i - 1]; // Storing the character at the index i-1
                char ks = s[k - 1]; // Storing the character at the index k-1
                char js = s[((i + k) / 2) - 1]; // Storing the character at the midpoint between i and k
                if (is != ks && ks != js && js != is) { // Checking if the characters at the three indices are different
                    result--; // Decrementing the result if they are
                }
            }
        }
    }

    printf("%ld\n", result); // Printing the final result to the console
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
