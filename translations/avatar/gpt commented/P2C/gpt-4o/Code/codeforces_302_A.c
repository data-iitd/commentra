#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    // Read two integers n and m from input
    scanf("%d %d", &n, &m);

    // Read the input string and count the number of '-' characters
    char inputString[100000]; // Assuming a maximum length for the input string
    scanf("%s", inputString);
    
    int sa = 0;
    for (int i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == '-') {
            sa++;
        }
    }

    // Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
    sa = (n - sa < sa) ? (n - sa) : sa;

    // Initialize an array to store results
    char ss[1000000]; // Assuming a maximum length for the results
    int index = 0;

    // Loop m times to read pairs of integers a and b
    for (int i = 0; i < m; i++) {
        int a, b;
        // Read two integers a and b from input
        scanf("%d %d", &a, &b);
        
        // Calculate the difference b - a
        b -= a;

        // Check if b is odd and less than or equal to double the count of '-'
        // Append "1\n" to the results if true, otherwise append "0\n"
        if (b % 2 == 1 && b <= sa * 2) {
            index += sprintf(ss + index, "1\n");
        } else {
            index += sprintf(ss + index, "0\n");
        }
    }

    // Print the concatenated results from the array
    printf("%s", ss);

    return 0;
}

// <END-OF-CODE>
