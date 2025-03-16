
#include<stdio.h>
// Include the standard input/output library header file

int main()
{
    int a, b, c;
    // Declare three integer variables: a, b, and c

    scanf("%d%d%d",&a,&b,&c);
    // Use the scanf function to read three integers from the standard input
    // and assign them to the variables a, b, and c respectively

    if(a<b && b<c)
    {
        printf("Yes\n");
        // If the condition a < b && b < c is true, print the string "Yes"
        // followed by a newline character to the standard output
    }
    else
    {
        printf("No\n");
        // If the condition a < b && b < c is false, print the string "No"
        // followed by a newline character to the standard output
    }

    return 0;
    // End the main function with a return statement of 0, indicating that
    // the program has run successfully
}