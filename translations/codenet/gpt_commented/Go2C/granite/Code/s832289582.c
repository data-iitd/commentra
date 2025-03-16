
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N: [1, 2e5]
// len(S) = N
// P: [2, 10000], prime
int main() {
    // Initialize the input scanner with a buffer size of 256 KB
    struct inputScanner *sc = newInputScanner(true, 256);
    
    // Read the integer values N and P, and the string S from input
    int N = sc->nextInt();
    int P = sc->nextInt();
    char *S = sc->nextStr();
    
    // Check the sub-numbers based on the conditions and print the result
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);
    
    // Free the allocated memory for the input scanner
    freeInputScanner(sc);
    
    return 0;
}

// checkSubNumbers determines the method to check sub-numbers based on the value of P
int checkSubNumbers(int N, int P, char *S) {
    switch (P) {
        case 2:
        case 5:
            // If P is 2 or 5, use the specific check for these primes
            return checkTwoOrFive(N, P, S);
        default:
            // For other primes, use the general check
            return checkNotTwoNorFive(N, P, S);
    }
}

// checkTwoOrFive counts the sub-numbers divisible by 2 or 5
int checkTwoOrFive(int N, int P, char *S) {
    int answer = 0;
    int n;
    
    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        // Convert the character to an integer
        n = atoi(S + i);
        
        // Check if the digit is divisible by P and update the answer
        if (n % P == 0) {
            answer += i + 1; // Count the number of valid sub-numbers
        }
    }
    return answer;
}

// checkNotTwoNorFive counts the sub-numbers for primes other than 2 and 5
int checkNotTwoNorFive(int N, int P, char *S) {
    int multiplier = 1; // Initialize the multiplier for 10^i % P
    int answer = 0;     // Initialize the answer counter
    int remainderLookup[P]; // Array to keep track of remainders
    int prevRemaider = -1; // Variable to store the previous remainder
    int digit, remainder, count;
    
    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0'; // Convert the character to an integer
        
        // Calculate the current remainder based on the previous remainder
        if (prevRemaider == -1) { // First digit case
            remainder = digit % P;
        } else {
            remainder = (((multiplier * digit) % P) + prevRemaider) % P;
        }
        
        // If the remainder is zero, increment the answer
        if (remainder == 0) {
            answer++;
        }
        
        // Update the count of sub-numbers with the current remainder
        count = remainderLookup[remainder];
        answer += count; // Add the count of previous occurrences of this remainder
        count++; // Increment the count for this remainder
        remainderLookup[remainder] = count; // Store the updated count
        prevRemaider = remainder; // Update the previous remainder
        multiplier = (multiplier * 10) % P; // Update the multiplier for the next digit
    }
    return answer;
}

// inputScanner wraps bufio.Scanner for easier input handling
struct inputScanner {
    struct bufio.Scanner *Scanner;
};

// newInputScanner initializes a new input scanner with a specified buffer size
struct inputScanner *newInputScanner(bool enabledScanWords, int sizeInKB) {
    struct bufio.Scanner *scanner = bufio.NewScanner(os.Stdin);
    if (enabledScanWords) {
        scanner.Split(bufio.ScanWords); // Set the scanner to split input by words
    }
    int capacity = sizeInKB * 1024; // Calculate the buffer capacity in bytes
    char *buf = malloc(capacity); // Create a buffer of the specified size
    scanner.Buffer(buf, capacity); // Set the buffer for the scanner
    return &struct inputScanner{
        Scanner: scanner,
    };
}

// nextInt reads the next integer from input
int nextInt(struct inputScanner *inputSc) {
    char *str = nextStr(inputSc); // Convert the next string to an integer
    int i = atoi(str);
    free(str); // Free the allocated memory for the string
    return i; // Return the integer value
}

// nextUInt64 reads the next uint64 from input
uint64_t nextUInt64(struct inputScanner *inputSc) {
    char *str = nextStr(inputSc); // Convert the next string to uint64
    uint64_t i = strtoull(str, NULL, 10);
    free(str); // Free the allocated memory for the string
    return i; // Return the uint64 value
}

// nextStr reads the next string from input
char *nextStr(struct inputScanner *inputSc) {
    inputSc->Scanner.Scan(); // Scan the next input
    char *str = malloc(strlen(inputSc->Scanner.Text()) + 1); // Create a new string
    strcpy(str, inputSc->Scanner.Text()); // Copy the scanned text to the new string
    return str; // Return the new string
}

// freeInputScanner frees the memory allocated for the input scanner
void freeInputScanner(struct inputScanner *inputSc) {
    free(inputSc->Scanner.Buffer); // Free the buffer memory
    free(inputSc); // Free the memory for the input scanner
}

// END-OF-CODE