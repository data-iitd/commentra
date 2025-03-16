#include <stdio.h>
#include <stdlib.h>

#define P 1000000007
#define INF 10000000010

int main() {
    // Read two inputs, one as an integer and the other as a float
    char sa[20], sb[20];
    scanf("%s %s", sa, sb);
    
    // Convert the first input to an integer
    int a = atoi(sa);
    
    // Convert the second input to a scaled integer
    double b_float = atof(sb);
    long long b = (long long)(b_float * 100 + 0.1);
    
    // Perform the calculation and print the result
    printf("%lld\n", (a * b) / 100);
    
    return 0;
}

// <END-OF-CODE>
