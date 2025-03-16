
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set up input and output streams
    FILE *inputStream = stdin;
    FILE *outputStream = stdout;

    // Read the number of elements
    int n;
    fscanf(inputStream, "%d", &n);

    // Initialize an array to count occurrences of each index (up to 1000)
    int array[1001] = {0};

    // Read n integers and count their occurrences
    for (int i = 0; i < n; i++) {
        int index;
        fscanf(inputStream, "%d", &index);
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
            fprintf(outputStream, "YES\n");
        } else {
            fprintf(outputStream, "NO\n");
        }
    } else {
        // For odd n, check if the maximum count is less than or equal to n/2 + 1
        if (countMax <= n / 2 + 1) {
            fprintf(outputStream, "YES\n");
        } else {
            fprintf(outputStream, "NO\n");
        }
    }

    return 0;
}
