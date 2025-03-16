#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the recursion limit is not applicable in C as it is in Python
    // However, we can define a large stack size if needed

    // Define constants
    const long long P = 1000000007;
    const long long INF = 1000000000 + 10;

    // Read input for two numbers 'a' and 'b'
    char sa[20], sb[20];
    scanf("%s %s", sa, sb);
    
    // Convert 'a' to integer
    int a = atoi(sa);
    
    // Convert 'b' to integer (multiplied by 100 and rounded)
    double b_float = atof(sb);
    int b = (int)(b_float * 100 + 0.1);

    // Calculate the product of 'a' and 'b' and print the result
    printf("%lld\n", (long long)a * b / 100);

    return 0;
}

// <END-OF-CODE>
