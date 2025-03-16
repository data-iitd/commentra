
#include<stdio.h>   // Include the input-output stream library
#include<stdlib.h>  // Include the standard library (not used in this code)
#include<string.h>  // Include the string library (not used in this code)
#include<math.h>    // Include the mathematical library (not used in this code)
using namespace std; // Use the standard namespace

#define INF 200000005 // Define a constant INF (not used in this code)

int main()
{
    int a, b; // Declare two integer variables a and b
    scanf("%d %d", &a, &b); // Read two integer inputs from the user

    // Check if both a and b are less than or equal to 8
    if (a <= 8 && b <= 8) 
        printf("Yay!\n"); // If true, print "Yay!"
    else 
        printf(":(\n"); // If false, print ":("

    return 0; // Return 0 to indicate successful execution
}
