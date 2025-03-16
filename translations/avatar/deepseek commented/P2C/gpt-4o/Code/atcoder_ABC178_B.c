#include <stdio.h>
#include <stdlib.h>

#define INF 10000000000000000000ULL
#define MOD 1000000007

// Function to read a list of integers from standard input
void read_integers(int *a, int *b, int *c, int *d) {
    scanf("%d %d %d %d", a, b, c, d);
}

// Main function
int main() {
    int a, b, c, d;
    read_integers(&a, &b, &c, &d);
    
    // Calculating the maximum of four possible products
    long long max_product = (long long)a * c;
    long long temp = (long long)b * d;
    if (temp > max_product) max_product = temp;
    
    temp = (long long)a * d;
    if (temp > max_product) max_product = temp;
    
    temp = (long long)b * c;
    if (temp > max_product) max_product = temp;

    printf("%lld\n", max_product);
    return 0;
}
// <END-OF-CODE>
