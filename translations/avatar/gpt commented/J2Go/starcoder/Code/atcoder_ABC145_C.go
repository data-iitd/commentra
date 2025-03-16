package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewScanner(os.Stdin)

	// Read the number of points (N) from stdin
	reader.Scan()
	N, _ := strconv.Atoi(reader.Text())

	// Initialize a 2D array to store the coordinates of the points
	pos := make([][]int, N)
	for i := 0; i < N; i++ {
		pos[i] = make([]int, 2)
	}

	// Loop to read the coordinates of each point
	for i := 0; i < N; i++ {
		// Read the x and y coordinates for the i-th point
		reader.Scan()
		line := strings.Split(reader.Text(), " ")
		pos[i][0], _ = strconv.Atoi(line[0])
		pos[i][1], _ = strconv.Atoi(line[1])
	}

	// Initialize a variable to accumulate the sum of distances
	sum := 0.0

	// Loop through each pair of points to calculate distances
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			// Skip the distance calculation if both points are the same
			if i == j {
				continue
			}

			// Calculate the distance between point i and point j and add it to the sum
			sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
		}
	}

	// Print the average distance by dividing the total sum by N
	fmt.Printf("%.2f\n", sum/float64(N))
}

// Method to calculate the Euclidean distance between two points (x1, y1) and (x2, y2)
func dist(x1, y1, x2, y2 int) float64 {
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

