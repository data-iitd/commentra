#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void run(FILE *input, FILE *output) {
    int N, D;
<<<<<<< HEAD
    fscanf(input, "%d %d", &N, &D);

    int count = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        fscanf(input, "%d %d", &x, &y);
        double distance = sqrt(x * x + y * y);
=======
    
    // Read the first line which contains two integers N and D.
    fscanf(input, "%d %d", &N, &D);
    
    int count = 0;
    
    // Iterate over each point and calculate the distance from the origin.
    for (int i = 0; i < N; i++) {
        int x, y;
        fscanf(input, "%d %d", &x, &y);
        
        // Calculate the Euclidean distance of the point from the origin.
        double distance = sqrt(x * x + y * y);
        
        // Check if the distance is within the given limit.
>>>>>>> 98c87cb78a (data updated)
        if (distance <= D) {
            count++;
        }
    }
<<<<<<< HEAD

=======
    
    // Write the count of points within the distance to the output.
>>>>>>> 98c87cb78a (data updated)
    fprintf(output, "%d\n", count);
}

int main() {
    run(stdin, stdout);
    return 0;
}

// <END-OF-CODE>
