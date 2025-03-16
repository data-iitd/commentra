#include <stdio.h> // Including standard input-output library
#include <string.h> // Including string library for string operations

int main() { // Starting the main function
    char S[100000]; // Declaring a string to hold the input
    scanf("%s", S); // Reading the input string
    int N = strlen(S); // Getting the length of the string

    int mod_arr[N]; // Creating an array to store intermediate results
    int mod_cnt[2019] = {0}; // Creating an array to count the frequency of each number, initialized to 0
    int radix = 1; // Initializing the radix to 1

    for (int i = 0; i < N; i++) { // Iterating through each character in the string
        int tmp = 0; // Initializing a temporary variable to store the intermediate result

        // Calculating the value of the current digit in the given base
        tmp = ((S[N - 1 - i] - '0') * radix) % 2019;

        // Updating the temporary variable with the carry from the previous digit
        if (i != 0) tmp = (tmp + mod_arr[i - 1]) % 2019;

        // Storing the intermediate result in the array
        mod_arr[i] = tmp;

        // Updating the frequency count of the current number in the array
        mod_cnt[tmp]++;

        // Updating the radix for the next iteration
        radix = (radix * 10) % 2019;
    }

    long long ans = 0; // Initializing a long long variable to store the final answer

    // Calculating the answer by summing up the terms of the formula
    for (int i = 0; i < 2019; i++) {
        ans += (long long)mod_cnt[i] * (mod_cnt[i] - 1) / 2; // Using long long to avoid overflow
    }

    printf("%lld\n", ans); // Printing the final answer
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
