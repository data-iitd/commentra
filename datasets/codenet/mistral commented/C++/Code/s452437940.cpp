#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;

// Main function begins here
int main()
{
    // Declare variables
    long long int a, b, x;

    // Read input values from standard input
    scanf("%lld%lld%lld",&a,&b,&x);

    // Calculate the difference between the number of complete x-blocks in b and a
    long long int s = (b/x - a/x);

    // If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
    if(a%x == 0) s++;

    // Print the result to standard output
    printf("%lld\n",s);

    // End of main function
    return 0;
}
