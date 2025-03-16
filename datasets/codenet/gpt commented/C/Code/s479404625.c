#include <stdio.h>
#include <string.h>

int main()
{
    // Declare character arrays to hold three strings
    char A[20], B[20], C[20];

    // Read three strings from user input
    scanf("%s %s %s", A, B, C);

    // Calculate the lengths of the first two strings
    int la = strlen(A), lb = strlen(B);

    // Check if the last character of A is the same as the first character of B
    // and if the last character of B is the same as the first character of C
    if (A[la - 1] == B[0] && B[lb - 1] == C[0])
    {
        // If both conditions are true, print "YES"
        printf("YES\n");
    }
    else
    {
        // If either condition is false, print "NO"
        printf("NO\n");
    }

    return 0; // Indicate that the program ended successfully
}
