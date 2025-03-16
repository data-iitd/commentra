#include<stdio.h>  // Include the standard input-output library
int main()        // Define the main function, the entry point of the program
{
    int a,b,c;     // Declare three integer variables
    scanf("%d%d%d",&a,&b,&c);  // Read three integer inputs from the user and store them in a, b, and c
    if(a<b&&b<c)  // Check if a is less than b and b is less than c
    {
        printf("Yes\n");  // If true, print "Yes"
    }
    else  // Otherwise
    {
        printf("No\n");  // Print "No"
    }
    return 0;  // Return 0 to indicate successful execution
}
