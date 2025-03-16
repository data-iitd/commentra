#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    // Declare static members for output stream and print writer
    FILE *outputStream = stdout;
    FILE *out = fopen("output.txt", "w"); // Using file for output to avoid flushing stdout

    // Initialize variables to keep track of sums and the minimum value
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    // Read the number of test cases
    int t;
    scanf("%d", &t);
    getchar(); // Consume newline character

    // Initialize priority queues for max and min values
    // Using arrays to simulate priority queues
    int pqmax[100000];
    int pqmin[100000];
    int pqmaxSize = 0, pqminSize = 0;

    // Process each test case
    while (t-- > 0) {
        // Read the input for the current test case
        char line[MAX_LINE_LENGTH];
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strcspn(line, "\n")] = 0; // Remove newline character
        char *s[3];
        int i = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            s[i++] = token;
            token = strtok(NULL, " ");
        }

        // If the command is '2', calculate and print the result
        if (s[0][0] == '2') {
            long long ans = min;
            ans *= pqminSize;
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmaxSize;
            ans1 = sumMax - ans1;
            fprintf(out, "%d %lld\n", min, (ans + ans1 + sumb));
        } 
        // If the command is '1', add the new value to the appropriate priority queue
        else {
            int in = atoi(s[1]);
            sumb += atoll(s[2]);

            if (in > min) {
                pqmax[pqmaxSize++] = in;
                sumMax += in;
            } else {
                pqmin[pqminSize++] = in;
                sumMin += in;
            }

            // Balance the priority queues
            if (pqminSize > pqmaxSize) {
                sumMax += pqmin[0];
                sumMin -= pqmin[0];
                pqmax[pqmaxSize++] = pqmin[0];
                for (int j = 0; j < pqminSize - 1; j++) {
                    pqmin[j] = pqmin[j + 1];
                }
                pqminSize--;
            }

            if (pqminSize < pqmaxSize) {
                sumMax -= pqmax[0];
                sumMin += pqmax[0];
                pqmin[pqminSize++] = pqmax[0];
                for (int j = 0; j < pqmaxSize - 1; j++) {
                    pqmax[j] = pqmax[j + 1];
                }
                pqmaxSize--;
            }

            // Update the minimum value
            min = pqmin[0];
        }
    }

    // Close the file to flush the output
    fclose(out);
    return 0;
}
