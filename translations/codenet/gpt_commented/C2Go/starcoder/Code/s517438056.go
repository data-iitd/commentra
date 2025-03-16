package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for number of vectors (N), dimensions (D), and loop counters
    var N, D, i, j, k, n int
    var l float64 // Variable to store the distance between two vectors

    // Read the number of vectors (N) and their dimensions (D) from user input
    fmt.Scanf("%d %d", &N, &D)

    // Allocate memory for a 2D array (matrix) to hold N vectors of D dimensions
    matrix := make([][]int, N)
    for i = 0; i < N; i++ {
        matrix[i] = make([]int, D)
    }

    // Read the vectors from user input and store them in the matrix
    for i = 0; i < N; i++ {
        for j = 0; j < D; j++ {
            fmt.Scanf("%d", &matrix[i][j])
        }
    }

    // Calculate the pairwise distances between all vectors
    for i = 0; i < N - 1; i++ {
        for j = i + 1; j < N; j++ {
            m := 0 // Variable to accumulate the squared differences
            // Calculate the squared distance between vector i and vector j
            for n = 0; n < D; n++ {
                m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m
            }
            // Calculate the Euclidean distance
            l = math.Sqrt(float64(m))
            // Check if the distance is an integer (i.e., if its ceiling equals its floor)
            if math.Ceil(l) == math.Floor(l) {
                k++
            }
        }
    }

    // Output the count of pairs of vectors with integer distances
    fmt.Printf("%d\n", k)
}

