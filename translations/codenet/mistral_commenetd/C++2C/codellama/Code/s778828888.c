#include <stdio.h>
#include <stdlib.h>

int main() // The entry point of the program
{
    int n, m, x; // Declare three integer variables n, m, and x

    scanf("%d %d %d", &n, &m, &x); // Read three integers from the standard input

    int a[105] = {}; // Declare and initialize an array a of size 105 with zeros

    for(int i = 0; i < m; ++i) // Iterate through m times
    {
        int temp; // Declare a temporary variable temp
        scanf("%d", &temp); // Read an integer from the standard input and store it in temp
        a[temp] = 1; // Set the value of the array element at index temp to 1
    }

    int ansl = 0, ansr = 0, i; // Declare and initialize three integer variables: ansl, ansr, and i

    for(i = x; i <= n; ++i) // Iterate through the range from x to n
    {
        ansr += a[i]; // Add the value of the array element at index i to the variable ansr
    }

    for(i=x; i >= 0; --i) // Iterate through the range from x to 0
    {
        ansl += a[i]; // Add the value of the array element at index i to the variable ansl
    }

    printf("%d\n", (ansl < ansr) ? ansl : ansr); // Print the minimum value between ansl and ansr
    return 0; // Indicate successful termination of the program
}

