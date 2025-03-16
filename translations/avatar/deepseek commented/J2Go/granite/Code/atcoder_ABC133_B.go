

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of vectors (N) and the dimension (D)
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	N, _ := strconv.Atoi(parts[0])
	D, _ := strconv.Atoi(parts[1])

	// Initialize the array to store the vectors
	vectors := make([][]int, N)
	for i := 0; i < N; i++ {
		vectors[i] = make([]int, D)
	}

	// Read each vector's components from the input
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		parts = strings.Split(strings.TrimSpace(line), " ")
		for j := 0; j < D; j++ {
			vectors[i][j], _ = strconv.Atoi(parts[j])
		}
	}

	// Initialize the answer variable
	answer := 0

	// Calculate the Euclidean distance between each pair of vectors
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			dist := 0
			for d := 0; d < D; d++ {
				x := vectors[i][d] - vectors[j][d]
				dist += x * x
			}
			sq := math.Sqrt(float64(dist))
			// Check if the distance is an integer and increment the answer if it is
			if math.Abs(sq-math.Floor(sq)) < 0.001 {
				answer++
			}
		}
	}

	// Print the answer
	fmt.Println(answer)
}

