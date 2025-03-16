#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

// FastReader for efficient input reading
struct FastReader { 
    FILE *br; 
    char *buf; 
    int size; 
    int pos; 
    int len; 
}; 

// Method to read the next token
char *next(struct FastReader *fr) { 
    while (fr->pos == fr->len) { 
        fr->pos = 0; 
        fr->len = fread(fr->buf, 1, fr->size, fr->br); 
        if (fr->len == 0) return NULL; 
    } 
    char *ret = fr->buf + fr->pos; 
    fr->pos++; 
    return ret; 
} 

// Method to read the next integer
int nextInt(struct FastReader *fr) { 
    char *str = next(fr); 
    return str ? atoi(str) : 0; 
} 

// Method to read the next long
long nextLong(struct FastReader *fr) { 
    char *str = next(fr); 
    return str ? atol(str) : 0; 
} 

// Method to read the next double
double nextDouble(struct FastReader *fr) { 
    char *str = next(fr); 
    return str ? atof(str) : 0; 
} 

// Method to read the next line
char *nextLine(struct FastReader *fr) { 
    char *str = next(fr); 
    return str ? str : ""; 
} 

// Method to initialize FastReader
void initFastReader(struct FastReader *fr, FILE *br, int size) { 
    fr->br = br; 
    fr->buf = (char *)malloc(size); 
    fr->size = size; 
    fr->pos = 0; 
    fr->len = 0; 
} 

// Method to close FastReader
void closeFastReader(struct FastReader *fr) { 
    free(fr->buf); 
} 

// Method to calculate the initial answer based on the grid size
int calculateAnswer(int n, int m) { 
    int answer = (n - 2) * 2; 
    return answer; 
} 

// Method to check if a row or column is banned
bool isBanned(int r, int c, int n, int m, int *bannedRows, int *bannedCols) { 
    for (int i = 0; i < m; i++) { 
        if (r == bannedRows[i] || c == bannedCols[i]) return true; 
    } 
    return false; 
} 

// Method to calculate the final answer
int calculateFinalAnswer(int n, int m, int *bannedRows, int *bannedCols) { 
    int answer = calculateAnswer(n, m); 
    for (int i = 0; i < m; i++) { 
        int r = bannedRows[i]; 
        int c = bannedCols[i]; 
        if (r > 1 && r < n && c > 1 && c < n) answer--; 
    } 
    if (n % 2 != 0) { 
        int mid = (n + 1) / 2; 
        if (!isBanned(mid, mid, n, m, bannedRows, bannedCols)) answer--; 
    } 
    return answer; 
} 

// Main method
int main() { 
    // Read the dimensions of the grid
    int n = nextInt(stdin); 
    int m = nextInt(stdin); 
    
    // Initialize sets to keep track of banned rows and columns
    int *bannedRows, *bannedCols; 
    bannedRows = (int *)malloc(m * sizeof(int)); 
    bannedCols = (int *)malloc(m * sizeof(int)); 
    
    // Read the banned rows and columns
    for (int i = 0; i < m; i++) { 
        int r = nextInt(stdin); 
        // Add to bannedRows if the row is within valid range
        if (r > 1 && r < n) bannedRows[i] = r; 
        int c = nextInt(stdin); 
        // Add to bannedCols if the column is within valid range
        if (c > 1 && c < n) bannedCols[i] = c; 
    } 
    
    // Calculate the final answer
    int answer = calculateFinalAnswer(n, m, bannedRows, bannedCols); 
    
    // Output the final answer
    printf("%d\n", answer); 
    
    // Free memory
    free(bannedRows); 
    free(bannedCols); 
    
    return 0; 
} 

