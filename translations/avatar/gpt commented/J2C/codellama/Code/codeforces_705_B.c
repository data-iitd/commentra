#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

// FastReader class to handle fast input
typedef struct FastReader { 
    FILE *br; 
    char *str; 
    char *token; 
    int len; 
} FastReader; 

// Constructor to initialize BufferedReader
FastReader* newFastReader() { 
    FastReader *fr = (FastReader*)malloc(sizeof(FastReader)); 
    fr->br = stdin; 
    fr->str = (char*)malloc(sizeof(char) * 1000000); 
    fr->token = (char*)malloc(sizeof(char) * 1000000); 
    fr->len = 0; 
    return fr; 
} 

// Method to read the next token from input
char* next(FastReader *fr) { 
    // Read new line if no tokens are available
    while (fr->token == NULL || strlen(fr->token) == 0) { 
        fgets(fr->str, 1000000, fr->br); 
        fr->token = strtok(fr->str, " \n"); 
    } 
    return fr->token; 
} 

// Method to read the next integer from input
int nextInt(FastReader *fr) { 
    return atoi(next(fr)); 
} 

// Method to read the next long from input
long nextLong(FastReader *fr) { 
    return atol(next(fr)); 
} 

// Method to read the next double from input
double nextDouble(FastReader *fr) { 
    return atof(next(fr)); 
} 

// Method to read the next line from input
char* nextLine(FastReader *fr) { 
    char *str = (char*)malloc(sizeof(char) * 1000000); 
    fgets(str, 1000000, fr->br); 
    return str; 
} 

// Create an instance of FastReader for input
FastReader *scan = newFastReader(); 

int main() { 
    int t = 1; // Number of test cases (currently set to 1)
    while (t-- > 0) { 
        solve(); // Call the solve method for processing
    } 
    return 0; 
} 

void solve() { 
    // Read the number of elements in the array
    int t = nextInt(scan); 
    int *arr = (int*)malloc(sizeof(int) * t); 
    
    // Populate the array with input values
    for (int i = 0; i < t; i++) { 
        arr[i] = nextInt(scan); 
    } 
    
    int prevWinner = 0; // Variable to track the previous winner
    
    // Iterate through the array to determine the winner for each element
    for (int i = 0; i < t; i++) { 
        // Check if the current element is 1
        if (arr[i] == 1) { 
            // If the previous winner is 0, set the previous winner to 2
            if (prevWinner == 0) { 
                prevWinner = 2; 
            } 
        } 
        
        // Determine the winner based on the previous winner and the current element
        if (prevWinner == 2 || prevWinner == 0) { 
            // If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) { 
                printf("2\n"); // Print winner 2
                prevWinner = 2; // Update previous winner
            } else { 
                printf("1\n"); // Print winner 1
                prevWinner = 1; // Update previous winner
            } 
        } else { 
            // If the previous winner is 1, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) { 
                printf("1\n"); // Print winner 1
                prevWinner = 1; // Update previous winner
            } else { 
                printf("2\n"); // Print winner 2
                prevWinner = 2; // Update previous winner
            } 
        } 
    } 
} 

