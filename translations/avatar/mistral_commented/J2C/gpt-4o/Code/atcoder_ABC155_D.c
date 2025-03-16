#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define INF 1000000000000000000LL

long long n;  // Number of elements in the array 'a'
long long k;  // A given value
long long *a; // The array to be processed

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int check(long long x) {  // A helper function to check if the condition is satisfied
    long long tot = 0;  // Initializing a variable to store the total number of elements that can be covered

    for (long long i = 0; i < n; i++) {  // Iterating through all the elements in the array 'a'
        long long now = a[i];  // Reading the current element
        long long l = 0, r = n;  // Initializing the left and right indices for the binary search

        if (now >= 0) {  // If the current element is non-negative
            while (l < r) {  // Performing binary search to find the index 'c' such that 'now * a[c]' is close to 'x'
                long long c = (l + r) / 2;
                if (now * a[c] < x) l = c + 1;  // If 'now * a[c]' is smaller than 'x', update the left index
                else r = c;  // Otherwise, update the right index
            }
            tot += l;  // Adding the index 'l' to the total number of elements that can be covered
        } else {  // If the current element is negative
            while (l < r) {  // Performing binary search to find the index 'c' such that 'now * a[c]' is greater than or equal to 'x'
                long long c = (l + r) / 2;
                if (now * a[c] >= x) l = c + 1;  // If 'now * a[c]' is greater than or equal to 'x', update the left index
                else r = c;  // Otherwise, update the right index
            }
            tot += (n - l);  // Adding the remaining elements to the total number of elements that can be covered
        }

        if (now * now < x) tot--;  // If the square of the current element is smaller than 'x', decrement the total number of elements that can be covered

        if (tot / 2 < k) return 1;  // If the total number of elements that can be covered is less than 'k', return true
    }

    return 0;  // Otherwise, return false
}

int main() {
    scanf("%lld", &n);  // Reading the number of elements in the array 'a'
    scanf("%lld", &k);  // Reading the given value 'k'
    a = (long long *)malloc(n * sizeof(long long));  // Allocating memory for the array 'a'

    for (long long i = 0; i < n; ++i) {  // Reading the elements of the array 'a'
        scanf("%lld", &a[i]);
    }

    qsort(a, n, sizeof(long long), compare);  // Sorting the elements of the array 'a' in ascending order

    long long l = -INF;  // Initializing the lower bound of the binary search range to a very large negative value
    long long r = INF;   // Initializing the upper bound of the binary search range to a very large positive value

    while (l + 1 < r) {  // Performing binary search to find the answer
        long long c = (l + r) / 2;
        if (check(c)) l = c;  // If the condition is satisfied, update the lower bound
        else r = c;  // Otherwise, update the upper bound
    }

    printf("%lld\n", l);  // Printing the answer
    free(a);  // Freeing the allocated memory for the array 'a'
    return 0;
}

// <END-OF-CODE>
