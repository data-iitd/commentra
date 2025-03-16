

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func solve(N int, x []int, y []int) {
    // Generate a list of indices from 0 to N-1
    indices := make([]int, N)
    for i := range indices {
        indices[i] = i
    }

    // Generate all permutations of the indices
    permutations := make([][]int, 0)
    for i := 0; i < N; i++ {
        for j := i + 1; j <= N; j++ {
            permutations = append(permutations, indices[i:j])
        }
    }

    // Initialize a list to store the total distances for each permutation
    distances := make([]float64, 0)

    // Iterate over each permutation
    for _, permutation := range permutations {
        // Initialize the total distance for the current permutation
        totalDistance := 0.0

        // Calculate the distance between consecutive points in the permutation
        for i := 0; i < N-1; i++ {
            f, t := permutation[i], permutation[i+1]
            distance := math.Sqrt(math.Pow(float64(x[t]-x[f]), 2)+math.Pow(float64(y[t]-y[f]), 2))
            totalDistance += distance
        }

        // Append the total distance of the current permutation to the distances list
        distances = append(distances, totalDistance)
    }

    // Calculate the average distance by averaging all stored distances
    result := 0.0
    for _, distance := range distances {
        result += distance
    }
    result /= float64(len(distances))

    // Print the result
    fmt.Println(result)
}

func main() {
    // Function to iterate over tokens in the input
    iterateTokens := func(scanner *bufio.Scanner) func() string {
        return func() string {
            scanner.Scan()
            return scanner.Text()
        }
    }

    // Open the input file
    file, err := os.Open(os.Args[1])
    if err!= nil {
        panic(err)
    }
    defer file.Close()

    // Create a scanner to read the input file
    scanner := bufio.NewScanner(file)

    // Read the number of points N
    N, err := strconv.Atoi(iterateTokens(scanner)())
    if err!= nil {
        panic(err)
    }

    // Initialize lists for x and y coordinates
    x := make([]int, N)
    y := make([]int, N)

    // Read the x and y coordinates for each point
    for i := 0; i < N; i++ {
        x[i], err = strconv.Atoi(iterateTokens(scanner)())
        if err!= nil {
            panic(err)
        }
        y[i], err = strconv.Atoi(iterateTokens(scanner)())
        if err!= nil {
            panic(err)
        }
    }

    // Call the solve function with the input values
    solve(N, x, y)
}

