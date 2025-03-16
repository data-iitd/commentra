#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Define a large constant for infinity
#define inf 1000000000

// Define a modulus value commonly used in competitive programming
#define mod 1000000007

// Define directional movements for 4 directions (up, right, down, left)
int dd[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// Define diagonal movements for 8 directions (including diagonals)
int ddn[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// Function to read a line of input and return it as a list of integers
int* LI() {
    char* str = (char*)malloc(1000000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    int len = strlen(str);
    int* arr = (int*)malloc((len / 2 + 1) * sizeof(int));
    int i = 0;
    for (int j = 0; j < len; j += 2) {
        arr[i++] = str[j] - '0';
    }
    arr[i] = -1;
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

// Function to read a line of input and return it as a list of strings
char** LS() {
    char* str = (char*)malloc(1000000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    int len = strlen(str);
    char** arr = (char**)malloc((len / 2 + 1) * sizeof(char*));
    int i = 0;
    for (int j = 0; j < len; j += 2) {
        arr[i] = (char*)malloc(2 * sizeof(char));
        arr[i][0] = str[j];
        arr[i][1] = str[j + 1];
        arr[i][2] = '\0';
        i++;
    }
    arr[i] = NULL;
    return arr;
}

// Function to read a single string from input
char* S() {
    char* str = (char*)malloc(1000000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    return str;
}

// Main function to execute the core logic of the program
int main() {
    // Read four integers from input
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Calculate the maximum value from the products of the pairs and return it
    int max = a * c;
    if (max < b * d) {
        max = b * d;
    }
    if (max < a * d) {
        max = a * d;
    }
    if (max < b * c) {
        max = b * c;
    }
    printf("%d", max);
    return 0;
}

