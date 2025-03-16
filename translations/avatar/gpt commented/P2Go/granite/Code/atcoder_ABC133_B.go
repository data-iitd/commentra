
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
	// Read the number of points (n) and the dimension (d) from input
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(parts[0])
	d, _ := strconv.Atoi(parts[1])

	// Read the coordinates of the points into a 2D slice
	points := make([][]float64, n)
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(line), " ")
		points[i] = make([]float64, d)
		for j := 0; j < d; j++ {
			points[i][j], _ = strconv.ParseFloat(parts[j], 64)
		}
	}

	// Define a function to calculate the Euclidean distance between two points
	dist := func(x, y []float64) float64 {
		tmp := 0.0
		// Calculate the squared differences for each dimension
		for i := 0; i < d; i++ {
			tmp += math.Pow(x[i]-y[i], 2)
		}
		// Return the square root of the sum of squared differences
		return math.Sqrt(tmp)
	}

	// Initialize a counter for pairs of points with integer distances
	count := 0

	// Iterate through each point and compare it with every other point
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			// Check if the distance between the two points is an integer
			if dist(points[i], points[j]).IsInt() {
				count++ // Increment the count if the distance is an integer
			}
		}
	}

	// Print the total count of pairs with integer distances
	fmt.Println(count)
}
