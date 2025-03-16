#include <stdio.h>

int main()
{
    int n;
    char s[100];

    // Read an integer input from the user
    scanf("%d", &n);

    // Read a string input from the user
    scanf("%s", s);

    // Check if the length of the string is odd
    if (n % 2 != 0)
    {
        // If the length is odd, print 'No' since it cannot be split into two equal halves
        printf("No\n");
    }
    // Check if the first half of the string is equal to the second half
    else if (strncmp(s, s + n / 2, n / 2) == 0)
    {
        // If both halves are equal, print 'Yes'
        printf("Yes\n");
    }
    else
    {
        // If the halves are not equal, print 'No'
        printf("No\n");
    }

    return 0;
}
