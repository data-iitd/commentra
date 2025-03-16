#include <stdio.h>
#include <math.h>

int main()
{
    // Read two integers a and b from input
    int a, b; 
    scanf("%d %d", &a, &b);

    // Convert b to string to determine its length
    char bstr[20];
    sprintf(bstr, "%d", b);
    
    // Calculate the number formed by concatenating a and b
    int num = a * pow(10, strlen(bstr)) + b;

    // Initialize a variable to find the square root of num
    int i;
    // Loop to check if there exists an integer i such that i*i equals num
    for (i = 1; i <= 100100; i++)
    {
        if (i * i == num) break; // If found, exit the loop
    }

    // Check if a valid integer i was found within the range
    if (i > 100100) 
        printf("No\n"); // If no such i exists, print "No"
    else 
        printf("Yes\n"); // If such i exists, print "Yes"
}
