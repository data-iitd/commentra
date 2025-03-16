
#include <stdio.h>
#include <string.h>

int main() {
    // Create a BufferedReader to read input from the console
    char buf[1000];
    fgets(buf, 1000, stdin);
    
    // Read the first line of input and split it into an array of strings
    char *inp = strtok(buf, " ");
    
    // Parse the first two elements of the input array as integers n and m
    int n = atoi(inp);
    inp = strtok(NULL, " ");
    int m = atoi(inp);
    
    // Initialize an array to hold the resulting strings
    char *ans[n];
    
    // Loop through each of the n lines of input
    for (int i = 0; i < n; i++) {
        // Read the current line of input
        fgets(buf, 1000, stdin);
        
        // Create a StringBuilder to construct the output for the current line
        char temp[m];
        memset(temp, 0, sizeof(temp));
        
        // Loop through each character in the current line
        for (int j = 0; j < m; j++) {
            // Check if the character is a '-'
            if (buf[j] == '-') {
                // Append '-' to the StringBuilder if it is
                temp[j] = '-';
            } else {
                // If the character is not '-', determine whether to append 'W' or 'B'
                if ((i + j) % 2 == 1) {
                    // Append 'W' for odd indices
                    temp[j] = 'W';
                } else {
                    // Append 'B' for even indices
                    temp[j] = 'B';
                }
            }
        }
        
        // Store the constructed string in the ans array
        ans[i] = (char *)malloc(sizeof(char) * (m + 1));
        strcpy(ans[i], temp);
    }
    
    // Output the resulting strings line by line
    for (int i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }
    
    return 0;
}
