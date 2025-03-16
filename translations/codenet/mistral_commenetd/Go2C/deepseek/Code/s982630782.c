#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to read a string from standard input
void scan(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vscanf(format, args);
    va_end(args);
}

int main() {
    // Initialize an empty map to store the frequency of each number
    int N;
    scan("%d", &N);
    int m[100001] = {0}; // Assuming the numbers will not exceed 100000
    // Read the N integers and store their frequencies in the map
    for (int i = 0; i < N; i++) {
        int num = readInt();
        m[num]++;
    }

    // Read the number of queries M
    int M;
    scan("%d", &M);
    // For each query, read the number B and the index C, and update the frequency of the number at index C in the map
    for (int i = 0; i < M; i++) {
        int B, C;
        scan("%d %d", &B, &C);
        m[C] += B;
    }

    // Initialize variables for calculating the sum
    int rest = N;
    long long sum = 0;
    // Iterate through the map and calculate the sum
    for (int i = 1; i <= 100000; i++) {
        int num = m[i];
        // If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
        if (num >= rest) {
            sum += rest * i;
            break;
        }
        // Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
        sum += num * i;
        rest -= num;
    }

    // Print the result
    printf("%lld\n", sum);

    return 0;
}
