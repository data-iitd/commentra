#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;

// Main function is the entry point of the program
int main()
{
    // Declare variables to store user input
    long long int a, b, x;
    
    // Read three long long integers from standard input
    scanf("%lld%lld%lld", &a, &b, &x);
    
    // Calculate the number of multiples of x between a and b inclusive
    long long int s = (b / x - a / x);
    
    // Check if a is a multiple of x and adjust the count accordingly
    if (a % x == 0)
        s++;
    
    // Print the result
    printf("%lld\n", s);
    
    return 0;
}