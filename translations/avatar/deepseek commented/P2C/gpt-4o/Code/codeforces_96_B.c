#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000000
#define MAX_SIZE 1000000

long long l[MAX_SIZE]; // Array to store generated numbers
int count = 0; // Counter for the number of generated numbers

// The gen function generates numbers containing only the digits 4 and 7 using recursion.
void gen(long long number, int four, int seven) {
    // If the number exceeds the limit, return without adding it to the list.
    if (number > LIMIT) {
        return;
    }
    // If the number is positive and the count of 4's equals the count of 7's, add it to the list.
    if (number > 0 && four == seven) {
        l[count++] = number;
    }
    // Recursively generate numbers by adding 4 or 7 to the current number.
    gen(number * 10 + 4, four + 1, seven);
    gen(number * 10 + 7, four, seven + 1);
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

// The main function takes an input, finds the smallest number in the list l that is greater than or equal to n, and prints it.
int main() {
    gen(0, 0, 0); // Start generating numbers with 0, 0, 0 counts of 4's and 7's.
    qsort(l, count, sizeof(long long), compare); // Sort the list l to easily find the smallest valid number.
    
    long long n;
    scanf("%lld", &n); // Read the input number n.
    long long ans = 0;
    
    // Iterate through the sorted list to find the smallest number greater than or equal to n.
    for (int i = 0; i < count; i++) {
        if (l[i] >= n) {
            ans = l[i];
            break;
        }
    }
    
    printf("%lld\n", ans); // Print the smallest number found.
    return 0;
}

// <END-OF-CODE>
