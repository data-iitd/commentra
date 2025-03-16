

#include <stdio.h>
#include <math.h>

int main() {
    int N, A[5], min_A = 100000000;
    scanf("%d", &N);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
        if (A[i] < min_A) {
            min_A = A[i];
        }
    }
    printf("%d\n", (int)ceil(N / (double)min_A) + 4);
    return 0;
}

# Step 1: Include necessary header files for input/output operations and mathematical functions.

int main() {

# Step 2: Define the main function for the C program.

    int N, A[5], min_A = 100000000;
    scanf("%d", &N);

# Step 3: Read an integer input N and initialize an array A of size 5 to store the five integer inputs. Also, initialize a variable min_A to a large value (e.g., 100000000) to keep track of the minimum value in A.

    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);

# Step 4: Read five integer inputs and store them in the array A.

        if (A[i] < min_A) {
            min_A = A[i];

# Step 5: Update the variable min_A to keep track of the minimum value in A.

        }
    }
    printf("%d\n", (int)ceil(N / (double)min_A) + 4);

# Step 6: Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result. Finally, print the result.

    return 0;
}

# Step 7: Close the main function and end with comment "