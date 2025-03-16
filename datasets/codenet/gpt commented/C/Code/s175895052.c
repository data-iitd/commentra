#include<stdio.h>

int main(void)
{
    // Declare a character array to hold the input string
    char n[10];

    // Read a string from standard input and store it in the array 'n'
    scanf("%s", n);

    // Check if the first three characters are the same or if the last three characters are the same
    if (((n[0] == n[1]) && (n[1] == n[2])) || ((n[1] == n[2]) && (n[2] == n[3])))
    {
        // If the condition is true, print "Yes"
        printf("Yes\n");
    }
    else
    {
        // If the condition is false, print "No"
        printf("No\n");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
