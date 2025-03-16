#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

// FastReader object to read input efficiently
struct FastReader { 
    FILE *br; 
    char *buf; 
    int size; 
    int pos; 
    int line; 
}; 

// Method to read the next token
char *next(struct FastReader *fr) { 
    while (fr->pos == fr->size) { 
        fr->pos = 0; 
        fr->size = fread(fr->buf, 1, 1 << 22, fr->br); 
        if (fr->size == 0) { 
            return NULL; 
        } 
    } 
    char *ret = fr->buf + fr->pos++; 
    if (*ret == '\n') { 
        fr->line++; 
    } 
    return ret; 
} 

// Method to read the next integer
int nextInt(struct FastReader *fr) { 
    char *ret = next(fr); 
    if (ret == NULL) { 
        return -1; 
    } 
    return atoi(ret); 
} 

// Method to read the next long
long nextLong(struct FastReader *fr) { 
    char *ret = next(fr); 
    if (ret == NULL) { 
        return -1; 
    } 
    return atol(ret); 
} 

// Method to read the next double
double nextDouble(struct FastReader *fr) { 
    char *ret = next(fr); 
    if (ret == NULL) { 
        return -1; 
    } 
    return atof(ret); 
} 

// Method to read the next line
char *nextLine(struct FastReader *fr) { 
    char *ret = next(fr); 
    if (ret == NULL) { 
        return NULL; 
    } 
    char *end = strchr(ret, '\n'); 
    if (end != NULL) { 
        *end = '\0'; 
    } 
    return ret; 
} 

// Main function
int main() { 
    // Read the dimensions of the grid
    int n = nextInt(stdin); 
    // Read the number of banned cells
    int m = nextInt(stdin); 

    // Initialize sets to keep track of banned rows and columns
    int *bannedRows, *bannedCols; 
    bannedRows = (int *)malloc(sizeof(int) * m); 
    bannedCols = (int *)malloc(sizeof(int) * m); 

    // Read each banned cell and add it to the appropriate set if it's not on the border
    for (int i = 0; i < m; i++) { 
        int r = nextInt(stdin); 
        if (r > 1 && r < n) bannedRows[i] = r; 
        int c = nextInt(stdin); 
        if (c > 1 && c < n) bannedCols[i] = c; 
    } 

    // Calculate the number of cells that can be reached, accounting for banned rows and columns
    int answer = (n - 2) * 2; 
    answer -= m; 
    answer -= m; 

    // Adjust the answer if the grid size is odd and the center cell is not banned
    if (n % 2 != 0) { 
        int mid = (n + 1) / 2; 
        if (!isIn(mid, bannedRows, m) && !isIn(mid, bannedCols, m)) { 
            answer--; 
        } 
    } 

    // Output the final answer
    printf("%d\n", answer); 
    // Close the output stream
    fclose(stdout); 
    return 0; 
} 

// Function to check if a value is in an array
bool isIn(int val, int *arr, int size) { 
    for (int i = 0; i < size; i++) { 
        if (arr[i] == val) { 
            return true; 
        } 
    } 
    return false; 
} 

