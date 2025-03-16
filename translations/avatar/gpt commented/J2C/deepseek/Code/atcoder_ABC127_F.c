#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main() {
    // Variables for reading input
    char line[MAX_LINE_SIZE];
    int t;

    // Read the number of test cases
    fgets(line, MAX_LINE_SIZE, stdin);
    t = atoi(line);

    // Arrays and priority queues for processing input
    int pqmax[t], pqmin[t];
    int pqmax_size = 0, pqmin_size = 0;
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    // Process each test case
    while (t-- > 0) {
        // Read the input line
        fgets(line, MAX_LINE_SIZE, stdin);
        char *s = strtok(line, " ");

        // If the first character is '2', calculate and print the result
        if (s[0] == '2') {
            long long ans = min;
            ans *= pqmin_size;
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax_size;
            ans1 = sumMax - ans1;

            // Print the minimum value and the calculated result
            printf("%d %lld\n", min, ans + ans1 + sumb);
        } else {
            // Parse the input values
            int in = atoi(strtok(NULL, " "));
            sumb += atoll(strtok(NULL, " ")); // Update the sum of additional values

            // Add the input value to the appropriate priority queue
            if (in > min) {
                pqmax[pqmax_size++] = in;
                sumMax += in;
            } else {
                pqmin[pqmin_size++] = in;
                sumMin += in;
            }

            // Balance the two heaps if necessary
            if (pqmin_size > pqmax_size) {
                sumMax += pqmin[0];
                sumMin -= pqmin[0];
                pqmax[pqmax_size++] = pqmin[0];
                pqmin_size--;
                pqmin[0] = pqmin[pqmin_size];
            }
            if (pqmin_size < pqmax_size) {
                sumMax -= pqmax[0];
                sumMin += pqmax[0];
                pqmin[pqmin_size++] = pqmax[0];
                pqmax_size--;
                pqmax[0] = pqmax[pqmax_size];
            }

            // Update the minimum value based on the current state of the heaps
            min = pqmin[0];
        }
    }

