#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void run(FILE *input, FILE *output) {
    int N, D;
    // Read N and D from the first line
    fscanf(input, "%d %d", &N, &D);

    int count = 0;
    // Iterate over each line of input
    for (int i = 0; i < N; i++) {
        int x, y;
        // Read the pair of integers
        fscanf(input, "%d %d", &x, &y);
        // Calculate the Euclidean distance from the origin (0, 0)
        double distance = sqrt(x * x + y * y);
        // Check if the distance is less than or equal to D
        if (distance <= D) {
            count++; // Increment the count if within distance
        }
    }
    // Output the total count of points within distance D
    fprintf(output, "%d\n", count);
}

int main() {
    // Call the run function with standard input and output
    run(stdin, stdout);
    return 0;
}

/* <END-OF-CODE> */
