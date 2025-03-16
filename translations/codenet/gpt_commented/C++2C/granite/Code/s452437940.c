
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;

int main()
{
    // Declare variables to hold the input values
    long long int a, b, x;

    // Read three long long integers from standard input
    scanf("%lld%lld%lld", &a, &b, &x);

    // Calculate the number of multiples of x in the range [a, b]
    long long int s = (b / x - a / x);

    // If 'a' is a multiple of 'x', include it in the count
    if (a % x == 0) s++;

    // Print the result: the total count of multiples of x in the range
    printf("%lld\n", s);

    return 0; // End of the program
}
