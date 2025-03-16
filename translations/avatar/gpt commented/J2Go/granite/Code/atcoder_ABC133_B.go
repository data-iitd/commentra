
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of vectors (N) and their dimensionality (D)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	N, _ := strconv.Atoi(parts[0])
	D, _ := strconv.Atoi(parts[1])

	// Initialize a 2D array to store the vectors
	vectors := make([][]int, N)
	for i := 0; i < N; i++ {
		vectors[i] = make([]int, D)
	}

	// Read each vector's components from the input
	for i := 0; i < N; i++ {
		scanner.Scan()
		line = scanner.Text()
		parts = strings.Split(line, " ")
		for j := 0; j < D; j++ {
			vectors[i][j], _ = strconv.Atoi(parts[j])
		}
	}

	// Initialize a counter for the number of pairs with integer distances
	answer := 0

	// Calculate the pairwise distances between all vectors
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			dist := 0

			// Calculate the squared distance between vector i and vector j
			for d := 0; d < D; d++ {
				x := vectors[i][d] - vectors[j][d]
				dist += x * x
			}

			// Calculate the Euclidean distance
			sq := math.Sqrt(float64(dist))

			// Check if the distance is an integer (within a small epsilon)
			if math.Abs(sq-math.Floor(sq)) < 0.001 {
				answer++
			}
		}
	}

	// Output the total count of pairs with integer distances
	fmt.Println(answer)
}

