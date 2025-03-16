#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    // Declare variables for the number of items (n) and the distance (d)
    int n, d;
    
    // Read input values for n and d from the user
    scanf("%d %d", &n, &d);

    // Calculate the effective range of coverage, which is (d*2 + 1)
    double a = d * 2 + 1;

    // Calculate and output the minimum number of groups needed to cover 'n' items
    // This is done by dividing 'n' by the coverage 'a' and rounding up to the nearest whole number
    printf("%d\n", ceil(n / a));

    return 0; // End of the program
}

