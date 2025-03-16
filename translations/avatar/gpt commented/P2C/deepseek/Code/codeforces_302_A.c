#include <stdio.h>
#include <string.h>

int main() {
    int n, m, sa, a, b, i;
    char input[1000];
    char ss[1000];
    
    // Read two integers n and m from input
    scanf("%d %d", &n, &m);
    
    // Count the number of '-' characters in the input string
    scanf("%s", input);
    sa = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '-') {
            sa++;
        }
    }
    
    // Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
    sa = (n - sa < sa) ? n - sa : sa;
    
    // Initialize an empty string to store results
    memset(ss, 0, sizeof(ss));
    
    // Loop m times to read pairs of integers a and b
    for (i = 0; i < m; i++) {
        // Read two integers a and b from input
        scanf("%d %d", &a, &b);
        
        // Calculate the difference b - a
        b -= a;
        
        // Check if b is odd and less than or equal to double the count of '-'
        // Append "1\n" to the results if true, otherwise append "0\n"
        if (b % 2 == 1 && b <= sa * 2) {
            strcat(ss, "1\n");
        } else {
            strcat(ss, "0\n");
        }
    }
    
    // Print the concatenated results from the string
    printf("%s", ss);
    
    return 0;
}
