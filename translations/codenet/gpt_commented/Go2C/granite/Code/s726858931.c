
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input

    char c = 'a'; // Initialize the current letter to 'a'

    int i, j;
    for (j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to 1 if the letter is found
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", c); // Print the missing letter
            return 0;
        }
        c++; // Move to the next letter
    }

    printf("None\n"); // If all letters from 'a' to 'z' are found, print "None"

    return 0;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    // No need to implement this function in C as it is already provided in the Go code
}

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from standard input
    return i; // Return the integer
}

// nextStr reads the next string from the input
char* nextStr() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input
    return s; // Return the scanned text as a string
}

// ---- main

int main() {
    scanInit(); // Initialize the scanner
    char* s = nextStr(); // Read the input string
    char c = 'a'; // Initialize the current letter to 'a'

    int i, j;
    for (j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to 1 if the letter is found
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", c); // Print the missing letter
            return 0;
        }
        c++; // Move to the next letter
    }

    printf("None\n"); // If all letters from 'a' to 'z' are found, print "None"

    return 0;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    // No need to implement this function in C as it is already provided in the Go code
}

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from standard input
    return i; // Return the integer
}

// nextStr reads the next string from the input
char* nextStr() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input
    return s; // Return the scanned text as a string
}

// ---- main

int main() {
    scanInit(); // Initialize the scanner
    char* s = nextStr(); // Read the input string
    char c = 'a'; // Initialize the current letter to 'a'

    int i, j;
    for (j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to 1 if the letter is found
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", c); // Print the missing letter
            return 0;
        }
        c++; // Move to the next letter
    }

    printf("None\n"); // If all letters from 'a' to 'z' are found, print "None"

    return 0;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    // No need to implement this function in C as it is already provided in the Go code
}

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from standard input
    return i; // Return the integer
}

// nextStr reads the next string from the input
char* nextStr() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input
    return s; // Return the scanned text as a string
}

// ---- main

int main() {
    scanInit(); // Initialize the scanner
    char* s = nextStr(); // Read the input string
    char c = 'a'; // Initialize the current letter to 'a'

    int i, j;
    for (j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to 1 if the letter is found
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", c); // Print the missing letter
            return 0;
        }
        c++; // Move to the next letter
    }

    printf("None\n"); // If all letters from 'a' to 'z' are found, print "None"

    return 0;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    // No need to implement this function in C as it is already provided in the Go code
}

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from standard input
    return i; // Return the integer
}

// nextStr reads the next string from the input
char* nextStr() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input
    return s; // Return the scanned text as a string
}

// ---- main

int main() {
    scanInit(); // Initialize the scanner
    char* s = nextStr(); // Read the input string
    char c = 'a'; // Initialize the current letter to 'a'

    int i, j;
    for (j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to 1 if the letter is found
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", c); // Print the missing letter
            return 0;
        }
        c++; // Move to the next letter
    }

    printf("None\n"); // If all letters from 'a' to 'z' are found, print "None"

    return 0;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    // No need to implement this function in C as it is already provided in the Go code
}

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from standard input
    return i; // Return the integer
}

// nextStr reads the next string from the input
char* nextStr() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input
    return s; // Return the scanned text as a string
}

// ---- main

int main() {
    scanInit(); // Initialize the scanner
    char* s = nextStr(); // Read the input string
    char c = 'a'; // Initialize the current letter to 'a'

    int i, j;
    for (j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to 1 if the letter is found
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", c); // Print the missing letter
            return 0;
        }
        c++; // Move to the next letter
    }

    printf("None\n"); // If all letters from 'a' to 'z' are found, print "None"

    return 0;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    // No need to implement this function in C as it is already provided in the Go code
}

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from standard input
    return i; // Return the integer
}

// nextStr reads the next string from the input
char* nextStr() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input
    return s; // Return the scanned text as a string
}

// ---- main

int main() {
    scanInit(); // Initialize the scanner
    char* s = nextStr(); // Read the input string
    char c = 'a'; // Initialize the current letter to 'a'

    int i, j;
    for (j = 0; j < 26; j++) {
        int found = 0; // Flag to check if the current letter is found in the input string
        for (i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = 1; // Set the flag to 1 if the letter is found
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", c); // Print the missing letter
            return 0;
        }
        c++; // Move to the next letter
    }

    printf("None\n"); // If all letters from 'a' to 'z' are found, print "None"

    return 0;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
    // No need to implement this function in C as it is already provided in the Go code
}

// nextInt reads the next integer from the input
int nextInt() {
    int i;
    scanf("%d", &i); // Read the next integer from standard input
    return i; // Return the integer
}

// nextStr reads the next string from the input
char* nextStr() {
    char s[1000001]; // Define a buffer to store the input string
    fgets(s, 1000001, stdin); // Read the input string from standard input
    return s; // Return the scanne