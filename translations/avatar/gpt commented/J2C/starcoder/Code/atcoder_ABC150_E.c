#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>

int main() {
    // Read the first line of input and split it into an array of strings
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    assert(read > 0);
    char *sa[] = split(line, " ");
    int n = atoi(sa[0]);
    // Read the second line of input and split it into an array of strings
    read = getline(&line, &len, stdin);
    assert(read > 0);
    sa = split(line, " ");
    // Initialize an integer array 'c' of size 'n'
    int *c = malloc(sizeof(int) * n);
    // Populate the array 'c' with integers from the input
    for (int i = 0; i < n; i++) {
        c[i] = atoi(sa[i]);
    }
    // Define a modulus value for calculations
    int mod = 1000000007;
    // If there is only one element, calculate and print the result directly
    if (n == 1) {
        printf("%d\n", c[0] * 2 % mod);
        return 0;
    }
    // Sort the array 'c' in parallel
    qsort(c, n, sizeof(int), compare);
    // Calculate powers of 2 for later use
    long b = power(2, n);
    long a = power(2, n - 2);
    // Initialize the answer variable
    long ans = 0;
    // Calculate the final answer using a loop
    for (int i = 2; i <= n + 1; i++) {
        // Calculate the value for the current iteration
        long val = a * i % mod;
        val *= c[n + 1 - i];
        val %= mod;
        // Accumulate the result
        ans += val;
        ans %= mod;
    }
    // Multiply the accumulated answer by 'b' and take modulus
    ans *= b;
    ans %= mod;
    // Print the final result
    printf("%ld\n", ans);
    return 0;
}

// Method to calculate (x^n) % mod using recursion
long power(long x, long n) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }
    // Define a modulus value for calculations
    int mod = 1000000007;
    // Recursively calculate power
    long val = power(x, n / 2);
    // Square the result and take modulus
    val = val * val % mod;
    // If n is odd, multiply by x and take modulus
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    // Return the final result
    return val;
}

// Method to compare two integers
int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

// Method to split a string into an array of strings
char **split(char *a_str, const char a_delim) {
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result) {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

