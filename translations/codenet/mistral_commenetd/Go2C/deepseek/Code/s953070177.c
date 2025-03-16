#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next string from the standard input
char* getNextString() {
    char *str = (char*)malloc(1000001 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to read the next integer from the standard input
int getNextInt() {
    char *str = getNextString();
    int num = atoi(str);
    free(str);
    return num;
}

// Function to read the next int64 from the standard input
long long getNextInt64() {
    char *str = getNextString();
    long long num = atoll(str);
    free(str);
    return num;
}

// Main function
int main() {
    // Read the first integer from the input
    int n = getNextInt();

    // Initialize an array 'aa' of size 'n+2'
    int aa[n+2];
    // Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
    int sum = 0;

    // Read the array 'aa' and calculate the sum of absolute differences between consecutive elements
    for (int i = 0; i < n; i++) {
        // Read the next integer from the standard input and store it in 'aa[i+1]'
        aa[i+1] = getNextInt();
        // Calculate the absolute difference between the current and previous elements and add it to the sum
        sum += abs(aa[i+1] - aa[i]);
    }
    // Calculate the absolute difference between the last two elements and add it to the sum
    sum += abs(aa[n+1] - aa[n]);

    // Iterate through the array 'aa' and print the answer for each subarray
    for (int i = 1; i < n+1; i++) {
        // Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
        // Print the answer
        printf("%d\n", ans);
    }

    return 0;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}
