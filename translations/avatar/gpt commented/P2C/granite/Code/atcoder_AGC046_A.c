
#include <stdio.h>
#include <math.h>

int main() {
    int x;
    // Take an integer input from the user
    scanf("%d", &x);

    // Calculate and print the number of equal parts in a full circle (360 degrees) 
    // that can be formed with the given angle x using the gcd
    printf("%d\n", 360 / gcd(360, x));

    return 0;
}
