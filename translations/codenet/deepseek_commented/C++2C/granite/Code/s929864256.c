
#include <stdio.h>
#include <stdlib.h> // Not used in this code
#include <string.h> // Not used in this code
#include <math.h>   // Not used in this code
#include <time.h>   // Not used in this code

int main() {
    long long a,b;
    scanf("%lld %lld",&a,&b); // Read two long long integers from standard input

    // Compute the maximum value among a+b, a-b, and a*b
    long long ans = a+b;
    ans = ans > a-b? ans : a-b;
    ans = ans > a*b? ans : a*b;

    printf("%lld\n",ans); // Print the maximum value

    return 0; // Return 0 indicating successful execution
}


