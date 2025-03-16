#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

// Structure to store the character array and its length
typedef struct { 
    char *s; 
    int n; 
} String; 

// Function to compare two character arrays with case insensitivity
int compare(char *a, char *b, int m) { 
    while (m-- > 0) { 
        // Convert characters to uppercase for comparison
        char a_ = toupper(*a); 
        char b_ = toupper(*b); 
        // Return the difference if characters do not match
        if (a_ != b_) return a_ - b_; 
        a++; 
        b++; 
    } 
    // Return 0 if all characters match
    return 0; 
} 

// Function to read a character array and return its length
int read(char *s) { 
    int n = 0; 
    char c; 
    while ((c = getchar()) != '\n') s[n++] = c; 
    s[n] = '\0'; 
    return n; 
} 

// Function to print a character array
void print(char *s) { 
    int n = strlen(s); 
    for (int i = 0; i < n; i++) putchar(s[i]); 
} 

int main() { 
    // Read the number of strings
    int n; 
    scanf("%d", &n); 
    String ss[n]; 
    
    // Read each string and convert it to a character array
    for (int i = 0; i < n; i++) { 
        ss[i].n = read(ss[i].s); 
        ss[i].s[ss[i].n] = '\0'; 
    } 
    
    // Read the character array to be modified
    char cc[100000]; 
    int m = read(cc); 
    
    // Read the character to be replaced
    char c; 
    scanf(" %c", &c); 
    char c_ = toupper(c); 
    
    // Determine the character to replace with
    char a = c == 'a' ? 'b' : 'a'; 
    char a_ = toupper(a); 
    
    // Array to track positions that can be marked as lucky
    int lucky[100000]; 
    memset(lucky, 0, sizeof(lucky)); 
    
    // Loop through each position in the character array
    for (int j = 0; j < m; j++) 
        for (int i = 0; i < n; i++) { 
            int l = ss[i].n; 
            // Check if the substring matches and mark lucky positions
            if (m - j >= l && compare(cc + j, ss[i].s, l) == 0) 
                for (int h = 0; h < l; h++) 
                    lucky[j + h] = 1; 
        } 
    
    // Replace characters in the original array based on lucky positions
    for (int j = 0; j < m; j++) 
        if (lucky[j]) { 
            // Replace with the determined character based on case
            if (tolower(cc[j]) == c) 
                cc[j] = isupper(cc[j]) ? a_ : a; 
            else 
                cc[j] = isupper(cc[j]) ? c_ : c; 
        } 
    
    // Print the modified character array
    print(cc); 
    printf("\n"); 
    return 0; 
}

