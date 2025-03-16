
#include <stdio.h>
#include <string.h>

int main() {
    // Create a BufferedReader to read input from the standard input stream
    FILE *br = fopen("input.txt", "r");
    
    // Create a PrintWriter to output results to the standard output stream
    FILE *pw = fopen("output.txt", "w");
    
    // Create an instance of the Fast class to process the input
    char s[100001];
    fgets(s, 100001, br);
    int cum[100001];
    cum[0] = cum[strlen(s) - 1] = 0;
    for (int i = 1; i < strlen(s) - 1; i++) {
        if (s[i] == s[i - 1])
            cum[i] = cum[i - 1] + 1; // Increment count if the current character is the same as the previous
        else
            cum[i] = cum[i - 1]; // Carry forward the previous count if different
    }
    
    // Read the number of queries from the input
    int q;
    fscanf(br, "%d", &q);
    
    // Process each query
    while (q--!= 0) {
        // Read the range for the query
        int l, r;
        fscanf(br, "%d %d", &l, &r);
        
        // Calculate and print the result for the current query
        fprintf(pw, "%d\n", cum[r - 1] - cum[l - 2]);
    }
    
    // Close the files
    fclose(br);
    fclose(pw);
    
    return 0;
}
