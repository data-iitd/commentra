#include <stdio.h>

#define rep(i,n) for(int i=0;i<n;i++) // Macro for repetition

int main() // Main function
{
    int h1, h2, m1, m2, k; // Declare variables for hours and minutes of first and second time, and the difference
    
    // Input the values of hours and minutes for the first and second time
    printf("Enter hours and minutes for the first time: ");
    scanf("%d %d", &h1, &m1);

    printf("Enter hours and minutes for the second time: ");
    scanf("%d %d", &h2, &m2);

    int ans = h2 * 60 + m2; // Calculate the total minutes of the second time
    printf("The total minutes of the second time are: %d\n", ans);

    ans -= (h1 * 60 + m1); // Subtract the total minutes of the first time from the total minutes of the second time
    printf("The difference in minutes is: %d\n", ans);

    printf("Enter the difference 'k': ");
    scanf("%d", &k); // Input the value of k
    ans -= k; // Subtract the given difference 'k' from the difference in minutes
    printf("The difference in minutes after subtracting %d is: %d\n", k, ans);

    // Convert the difference in minutes to hours and minutes
    int hours = ans / 60;
    int minutes = ans % 60;

    printf("%d hours and %d minutes\n", hours, minutes); // Output the result

    return 0;
}

// <END-OF-CODE>
