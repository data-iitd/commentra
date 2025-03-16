#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Set up input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    FILE *in = fopen(inputStream, "r"); 
    FILE *out = fopen(outputStream, "w"); 
    
    // Create an instance of TaskC to solve the problem
    TaskC solver = new TaskC(); 
    // Call the solve method with test number 1
    solver.solve(1, in, out); 
    
    // Close the output stream
    fclose(out); 
    return 0; 
} 

static class TaskC { 
    public void solve(int testNumber, FILE *in, FILE *out) { 
        // Read the number of strings
        int n; 
        fscanf(in, "%d", &n); 
        // Initialize an array to count occurrences of specific starting letters
        long cnt[5]; 
        memset(cnt, 0, sizeof(cnt)); // Fill the count array with zeros
        
        // Process each string input
        for (int i = 0; i < n; ++i) { 
            char str[100]; 
            fscanf(in, "%s", str); 
            // Increment the count based on the first character of the string
            if (str[0] == 'M') { 
                cnt[0]++; 
            } else if (str[0] == 'A') { 
                cnt[1]++; 
            } else if (str[0] == 'R') { 
                cnt[2]++; 
            } else if (str[0] == 'C') { 
                cnt[3]++; 
            } else if (str[0] == 'H') { 
                cnt[4]++; 
            } 
        } 
        
        // Calculate the result based on combinations of counts
        long res = cnt[0] * cnt[1] * cnt[2] + 
                   cnt[0] * cnt[1] * cnt[3] + 
                   cnt[0] * cnt[1] * cnt[4] + 
                   cnt[0] * cnt[2] * cnt[3] + 
                   cnt[0] * cnt[2] * cnt[4] + 
                   cnt[0] * cnt[3] * cnt[4] + 
                   cnt[1] * cnt[2] * cnt[3] + 
                   cnt[1] * cnt[2] * cnt[4] + 
                   cnt[1] * cnt[3] * cnt[4] + 
                   cnt[2] * cnt[3] * cnt[4]; 
        
        // Output the result
        fprintf(out, "%ld\n", res); 
    } 
} 

