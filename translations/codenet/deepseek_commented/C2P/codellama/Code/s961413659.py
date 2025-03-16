#include<stdio.h>
int main()
{
    int a, b;
    // Read two integers from the user input
    scanf("%d %d", &a, &b);
    
    // Check if either of the integers is 1, and if so, change them to 14
    if (a == 1)
        a = 14;
    if (b == 1)
        b = 14;
    
    // Compare the two integers and print the appropriate result
    if (a < b)
        printf("Bob\n");
    else if (a > b)
        printf("Alice\n");
    else
        printf("Draw\n");
    return 0;
}
