#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Set up input and output streams
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;
    
    // Read the number of elements
    int n;
    fscanf(inputFile, "%d", &n);
    
    // Initialize an array to count occurrences of each index (up to 1000)
    int array[1001];
    memset(array, 0, sizeof(array));
    
    // Read n integers and count their occurrences
    for (int i = 0; i < n; i++) {
        int index;
        fscanf(inputFile, "%d", &index);
        array[index]++;
    }
    
    // Determine the maximum count of any index
    int countMax = -1;
    for (int i = 1; i < 1001; i++) {
        if (countMax < array[i])
            countMax = array[i];
    }
    
    // Check if the maximum count is within allowed limits based on n being even or odd
    if (n % 2 == 0) {
        // For even n, check if the maximum count is less than or equal to n/2
        if (countMax <= n / 2) {
            fprintf(outputFile, "YES\n");
        } else {
            fprintf(outputFile, "NO\n");
        }
    } else {
        // For odd n, check if the maximum count is less than or equal to n/2 + 1
        if (countMax <= n / 2 + 1) {
            fprintf(outputFile, "YES\n");
        } else {
            fprintf(outputFile, "NO\n");
        }
    }
    
    // Close the output file (not necessary for stdout, but good practice)
    fclose(outputFile);
    
    return 0;
}
