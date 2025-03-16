

#include <stdio.h> // Standard input/output library
#include <string.h> // String manipulation library

int main() {
    // Main function to start the program

    int n; // Number of test cases
    char str[10]; // String to store input

    long long cnt[5] = {0}; // Array of size 5 to store counts

    scanf("%d", &n); // Read the number of test cases

    for (int i = 0; i < n; ++i) {
        // Loop through each test case

        scanf("%s", str); // Read a string from input

        if (str[0] == 'M') {
            // If the first character of the string is 'M', increment the count of 'M'
            cnt[0]++;
        } else if (str[0] == 'A') {
            // If the first character of the string is 'A', increment the count of 'A'
            cnt[1]++;
        } else if (str[0] == 'R') {
            // If the first character of the string is 'R', increment the count of 'R'
            cnt[2]++;
        } else if (str[0] == 'C') {
            // If the first character of the string is 'C', increment the count of 'C'
            cnt[3]++;
        } else if (str[0] == 'H') {
            // If the first character of the string is 'H', increment the count of 'H'
            cnt[4]++;
        }
    }

    long long res = cnt[0] * cnt[1] * cnt[2] + // Calculate the first product
                    cnt[0] * cnt[1] * cnt[3] + // Calculate the second product
                    cnt[0] * cnt[1] * cnt[4] + // Calculate the third product
                    cnt[0] * cnt[2] * cnt[3] + // Calculate the fourth product
                    cnt[0] * cnt[2] * cnt[4] + // Calculate the fifth product
                    cnt[0] * cnt[3] * cnt[4] + // Calculate the sixth product
                    cnt[1] * cnt[2] * cnt[3] + // Calculate the seventh product
                    cnt[1] * cnt[2] * cnt[4] + // Calculate the eighth product
                    cnt[1] * cnt[3] * cnt[4] + // Calculate the ninth product
                    cnt[2] * cnt[3] * cnt[4]; // Calculate the tenth product

    printf("%lld\n", res); // Write the result to the output

    return 0; // Return 0 to indicate successful execution
}

