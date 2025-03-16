#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN 100000

// Function to read a line of integers from input
int* LI() {
    static char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    int* arr = (int*)malloc(sizeof(int) * 10000);
    int n = 0;
    char* token = strtok(buf, " ");
    while (token != NULL) {
        arr[n++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read a line of integers from input and convert them to zero-based index
int* LI_() {
    static char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    int* arr = (int*)malloc(sizeof(int) * 10000);
    int n = 0;
    char* token = strtok(buf, " ");
    while (token != NULL) {
        arr[n++] = atoi(token) - 1;
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read a line of floats from input
float* LF() {
    static char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    float* arr = (float*)malloc(sizeof(float) * 10000);
    int n = 0;
    char* token = strtok(buf, " ");
    while (token != NULL) {
        arr[n++] = atof(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read a line of strings from input
char** LS() {
    static char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    char** arr = (char**)malloc(sizeof(char*) * 10000);
    int n = 0;
    char* token = strtok(buf, " ");
    while (token != NULL) {
        arr[n++] = token;
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read a single integer from input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single float from input
float F() {
    float x;
    scanf("%f", &x);
    return x;
}

// Function to read a single string from input
char* S() {
    static char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    char* str = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
    strcpy(str, buf);
    return str;
}

// Function to print a string and flush the output buffer
void pf(char* s) {
    printf("%s", s);
    fflush(stdout);
}

// Main function to process the input and return the result
char main() {
    // Reading a string from input
    char* s = S();
    // Reading an integer k from input
    int k = I();
    int l = 0;  // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '1') {
            break;
        }
        l++;
    }
    
    // If the count of leading '1's is greater than or equal to k, return '1'
    if (l >= k) {
        return '1';
    }
    
    // Otherwise, return the character at position l in the string
    return s[l];
}

// Print the result of the main function
int main() {
    printf("%c\n", main());
    return 0;
}
