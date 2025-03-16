
/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <stdio.h> // Include the Standard Input/Output library

int main()
{
    int n=1; // Initialize n with 1
    while (n--) {
        int ans = 0; // Declare a variable for the answer
        scanf("%d",&n); // Read the input number
        printf("%d\n",!n); // Output the boolean negation of n
    }
    return 0; // Return 0 to indicate successful execution
}
