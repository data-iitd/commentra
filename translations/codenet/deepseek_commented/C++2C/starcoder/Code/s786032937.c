#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    // Step 3: Read an integer input
    int n;
    scanf("%d", &n);

    // Step 4: Perform a calculation
    // The formula (n - 2) * 180 calculates the sum of internal angles of an n-sided polygon
    printf("%d\n", (n - 2) * 180);

    // Step 5: Output the result
    // The result is printed to the console

    // Step 6: Return from the main function
    return 0;
}

