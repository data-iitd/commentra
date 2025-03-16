#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a number from base 10 to base N
char* TenToN(int number, int n) {
    char* s = (char*)malloc(32); // Allocate memory for the result string
    int index = 0; // Index for the result string
    int tmp = number; // Temporary variable to hold the current number

    do {
        int remainder = tmp % n; // Get the remainder
        s[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A'); // Convert to character
        tmp /= n; // Divide the temporary number by the base
    } while (tmp > 0);

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = s[i];
        s[i] = s[index - i - 1];
        s[index - i - 1] = temp;
    }
    s[index] = '\0'; // Null-terminate the string
    return s; // Return the converted string
}

int main() {
    int N, K;
    // Read two integers N and K from input
    scanf("%d %d", &N, &K);
<<<<<<< HEAD
    // Convert the number N from base 10 to base K
    char* s = TenToN(N, K);
    // Print the length of the resulting string
    printf("%lu\n", strlen(s));
=======
    
    // Convert the number N from base 10 to base K
    char* s = TenToN(N, K);
    
    // Print the length of the resulting string
    printf("%lu\n", strlen(s));
    
>>>>>>> 98c87cb78a (data updated)
    free(s); // Free the allocated memory
    return 0;
}

/*==========================================
 *             Library
 *==========================================*/

// Function to read an integer from input
int readInt() {
    int read;
    scanf("%d", &read); // Read the next input
    return read; // Return the read integer
}

// Function to convert an integer to a string
char* i2s(int i) {
    char* strVal = (char*)malloc(12); // Allocate memory for the string
    sprintf(strVal, "%d", i); // Convert integer to string
    return strVal; // Return the string value
}

// Function to convert a string to an integer
int s2i(const char* s) {
    return atoi(s); // Convert string to integer
}

// Function to calculate the sum of an array of integers
int sum(int* arr, int length) {
    int total = 0; // Initialize sum
    for (int i = 0; i < length; i++) {
        total += arr[i]; // Add each value to the sum
    }
    return total; // Return the total sum
}

// Function to split a string into an array of strings
char** split(const char* s, int* count) {
    char* temp = strdup(s); // Duplicate the string
    char* token;
    char** result = NULL;
    *count = 0;

    token = strtok(temp, " ");
    while (token != NULL) {
        result = realloc(result, sizeof(char*) * (*count + 1)); // Resize the result array
        result[*count] = strdup(token); // Duplicate the token
        (*count)++;
<<<<<<< HEAD
        token = strtok(NULL, " "); // Get the next token
    }
    free(temp); // Free the duplicated string
=======
        token = strtok(NULL, " ");
    }
    free(temp); // Free the temporary string
>>>>>>> 98c87cb78a (data updated)
    return result; // Return the array of strings
}

// Function to reverse an array of integers
void reverse(int* arr, int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp; // Swap elements to reverse the array
    }
}

// Function to initialize an array with a given value
void initialize(int* arr, int length, int init) {
    if (length == 0) return; // Do nothing if the array is empty
    arr[0] = init; // Set the first element to the initial value
    for (int i = 1; i < length; i++) {
        arr[i] = arr[0]; // Initialize the rest of the array
    }
}

// Example function for regular expressions (not implemented in C)
// Example function for stable sorting (not implemented in C)

