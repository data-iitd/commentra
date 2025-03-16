#include <stdio.h>

int main()
{
    int n;
    char s[100];

    // Take an integer input from the user
    scanf("%d", &n);

    // Take a string input from the user
    scanf("%s", s);

    // Check if n is odd
    if (n % 2 != 0)
    {
        // Print 'No' if n is odd
        printf("No\n");
    }
    // If n is even, compare the first half of the string with the second half
    else if (strncmp(s, s + n/2, n/2) == 0)
    {
        // Print 'Yes' if the first half is equal to the second half
        printf("Yes\n");
    }
    else
    {
        // Print 'No' if the first half is not equal to the second half
        printf("No\n");
    }

    return 0;
}
