
#include<stdio.h> 

int main()
{
    // Declare four integer variables to hold input values
    int a, b, c, d; 

    // Read four integer values from user input
    scanf("%d %d %d %d", &a, &b, &c, &d); 

    // Check if the product of a and b is odd and the sum of c and d is odd
    if (a * b % 2 == 1 && (c + d) % 2 == 1)
    {
        // If both conditions are true, output "No"
        printf("No\n");
    }
    else
    {
        // If either condition is false, output "Yes"
        printf("Yes\n");
    }
}
