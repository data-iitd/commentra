#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare static variables for output stream and print writer
static FILE *outputStream = stdout;
static FILE *out = outputStream;

int main() {
    // Initialize BufferedReader to read input from System.in
    char *br = (char *)malloc(sizeof(char) * 1000000);
    fgets(br, 1000000, stdin);
    
    // Read the number of test cases
    int t = atoi(br);
    
    // Initialize priority queues for max and min values
    int *pqmax = (int *)malloc(sizeof(int) * t);
    int *pqmin = (int *)malloc(sizeof(int) * t);
    
    // Initialize variables to keep track of sums and the minimum value
    long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;
    
    // Process each test case
    while (t-- > 0) {
        // Read the input for the current test case
        char *s = (char *)malloc(sizeof(char) * 1000000);
        fgets(s, 1000000, stdin);
        
        // If the command is '2', calculate and print the result
        if (s[0] == '2') {
            long ans = min;
            ans *= pqmin[t];
            ans -= sumMin;
            long ans1 = min;
            ans1 *= pqmax[t];
            ans1 = sumMax - ans1;
            fprintf(out, "%d %ld\n", min, ans + ans1 + sumb);
        } 
        // If the command is '1', add the new value to the appropriate priority queue
        else {
            int in = atoi(s);
            sumb += atol(s);
            
            if (in > min) {
                pqmax[t] = in;
                sumMax += in;
            } else {
                pqmin[t] = in;
                sumMin += in;
            }
            
            // Balance the priority queues
            if (pqmin[t] > pqmax[t]) {
                sumMax += pqmin[t];
                sumMin -= pqmin[t];
                pqmax[t] = pqmin[t];
            }
            
            if (pqmin[t] < pqmax[t]) {
                sumMax -= pqmax[t];
                sumMin += pqmax[t];
                pqmin[t] = pqmax[t];
            }
            
            // Update the minimum value
            min = pqmin[t];
        }
    }
    
    // Close the print writer to flush the output
    fclose(out);
    return 0;
}

