#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define P 1000000007
#define INF 10000000010

void main() {
    // Declare variables
    char sa[10], sb[10];
    int a;
    int b;
    int result;

    // Read two values from input: one as a string and the other as a float in string format
    scanf("%s %s", sa, sb);

    // Convert the first value to an integer
    a = atoi(sa);

    // Convert the second value to an integer representing cents (by multiplying by 100)
    b = (int)(atof(sb) * 100 + 0.1);

    // Calculate the product of a and b, divided by 100 to get the final result
    result = a * b / 100;

    // Print the result
    printf("%d\n", result);
}
