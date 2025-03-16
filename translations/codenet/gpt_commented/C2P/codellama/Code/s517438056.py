#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void) {
    # Declare variables for number of vectors (N), dimensions (D), and loop counters
    N, D, i, j, k = 0, n = 0
    l = 0 # Variable to store the distance between two vectors
    matrix = [] # Pointer to a 2D array to hold the vectors

    # Read the number of vectors (N) and their dimensions (D) from user input
    scanf("%d%d", &N, &D)

    # Allocate memory for a 2D array (matrix) to hold N vectors of D dimensions
    for i in range(N):
        matrix.append([])
        for j in range(D):
            matrix[i].append(0)

    # Read the vectors from user input and store them in the matrix
    for i in range(N):
        for j in range(D):
            scanf("%d", &matrix[i][j])

    # Calculate the pairwise distances between all vectors
    for i in range(N - 1):
        for j in range(i + 1, N):
            m = 0 # Variable to accumulate the squared differences
            # Calculate the squared distance between vector i and vector j
            for n in range(D):
                m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m
            # Calculate the Euclidean distance
            l = sqrt(m)
            # Check if the distance is an integer (i.e., if its ceiling equals its floor)
            if ceil(l) == floor(l):
                k += 1

    # Output the count of pairs of vectors with integer distances
    print(k)

    # Free the allocated memory for the matrix
    free(matrix)
    return 0
}

