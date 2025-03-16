#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Function to calculate the power of a number x raised to the power n
long power(long x, long n) {
    if (n == 0) { // Base case when n is 0
        return 1;
    }

    long val = power(x, n / 2); // Recursively calculating the square of x raised to the power n/2

    // If n is odd, multiplying the result with x
    if (n % 2 == 1) {
        val = val * x;
    }

    // Returning the final result
    return val;
}

// Function to sort the array in parallel
void sort(int *c, int n) {
    // Initializing a boolean variable to true
    bool swapped = true;

    // Iterating until the boolean variable is false
    while (swapped) {
        // Initializing the boolean variable to false
        swapped = false;

        // Iterating through the array from index 0 to n-1
        for (int i = 0; i < n - 1; i++) {
            // If the current element is greater than the next element
            if (c[i] > c[i + 1]) {
                // Swapping the values of the current and next element
                int temp = c[i];
                c[i] = c[i + 1];
                c[i + 1] = temp;

                // Setting the boolean variable to true
                swapped = true;
            }
        }
    }
}

// Function to calculate the value of b and a
void calculate(int *c, int n, int mod) {
    // Calculating the value of b
    long b = power(2, n);

    // Calculating the value of a
    long a = power(2, n - 2);

    // Initializing the variable ans to 0
    long ans = 0;

    // Iterating through the array from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long val = a * i % mod;

        // Multiplying the value of val with the current element of the array c[n+1-i]
        val *= c[n + 1 - i];

        // Taking the modulus of the product to ensure the result is within the range of modulus
        val %= mod;

        // Adding the value of val to the variable ans
        ans += val;

        // Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
        ans %= mod;
    }

    // Multiplying the value of ans with the value of b
    ans *= b;

    // Taking the modulus of the product to ensure the result is within the range of modulus
    ans %= mod;

    // Printing the final result
    printf("%ld\n", ans);
}

// Driver function to start the execution of the program
int main() {
    // Reading the first line of input and splitting it into an array of strings
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    char *sa[] = split(line, " ");

    // Reading the second line of input and splitting it into an array of strings
    getline(&line, &len, stdin);
    char *sb[] = split(line, " ");

    // Parsing the first element of the array as an integer representing the size of the array
    int n = atoi(sa[0]);

    // Creating an integer array of size n
    int *c = (int *) malloc(n * sizeof(int));

    // Initializing the array c with the input values
    for (int i = 0; i < n; i++) {
        c[i] = atoi(sb[i]);
    }

    // Closing the BufferedReader to free up resources
    free(line);

    // Defining a constant value for modulus
    int mod = 1000000007;

    // Checking if the size of the array is 1
    if (n == 1) {
        // Printing the result for the case when the size of the array is 1
        printf("%d\n", c[0] * 2 % mod);
        return 0; // Exiting the method after printing the result
    }

    // Sorting the array c in parallel using sort() function
    sort(c, n);

    // Calculating the values of b and a
    calculate(c, n, mod);

    // Returning 0 to the system to indicate successful execution of the program
    return 0;
}

// Function to split a string into an array of strings
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

    result = (char **) malloc(sizeof(char *) * count);

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

