#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// FastReader class to handle fast input
class FastReader { 
    FILE *br; 
    char *st; 
    
    // Constructor initializes BufferedReader for input
    public: 
    FastReader() { 
        br = fopen("input.txt", "r"); 
    } 
    
    // Method to read the next token from input
    char *next() { 
        // Check if there are no more tokens available
        while (st == NULL || !strtok(st, " ")) { 
            try { 
                // Read a new line and tokenize it
                st = fgets(br); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        } 
        // Return the next token
        return strtok(st, " "); 
    } 
    
    // Method to read the next integer from input
    int nextInt() { 
        return atoi(next()); 
    } 
    
    // Method to read the next long from input
    long nextLong() { 
        return atol(next()); 
    } 
    
    // Method to read the next double from input
    double nextDouble() { 
        return atof(next()); 
    } 
    
    // Method to read the next line from input
    char *nextLine() { 
        char *str = ""; 
        try { 
            str = fgets(br); 
        } catch (IOException e) { 
            e.printStackTrace(); 
        } 
        return str; 
    } 
}; 

// Main function
int main() { 
    // Create an instance of FastReader for input
    FastReader sc = new FastReader(); 
    
    // Read two integers n and m from input
    int n = sc.nextInt(); 
    int m = sc.nextInt(); 
    
    // Reverse the integer m and store the result in t
    int t = reverse(m); 
    
    // Print the sum of t and n
    printf("%d\n", t + n); 
    return 0; 
} 

// Method to reverse the digits of an integer n
int reverse(int n) { 
    // If n is a single digit, return n multiplied by 10
    if (n < 10) return n * 10; 
    
    int t = n, r = 0; 
    
    // Loop to reverse the digits of n
    while (t > 0) { 
        r = (r * 10) + t % 10; // Add the last digit of t to r
        t = t / 10; // Remove the last digit from t
    } 
    
    // Return the reversed integer
    return r; 
} 

