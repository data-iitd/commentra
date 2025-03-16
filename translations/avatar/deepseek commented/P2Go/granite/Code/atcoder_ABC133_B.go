
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
	// Read the number of points and the dimension from the input
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(tokens[0])
	d, _ := strconv.Atoi(tokens[1])

	// Read n points, each with d coordinates, and store them in a 2D slice called points
	points := make([][]float64, n)
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		tokens := strings.Split(strings.TrimSpace(line), " ")
		points[i] = make([]float64, d)
		for j := 0; j < d; j++ {
			points[i][j], _ = strconv.ParseFloat(tokens[j], 64)
		}
	}

	// Define a function to calculate the Euclidean distance between two points
	dist := func(x, y []float64) float64 {
		var tmp float64
		for i := 0; i < d; i++ {
			tmp += math.Pow(x[i]-y[i], 2)
		}
		return math.Sqrt(tmp)
	}

	// Initialize a counter to keep track of pairs with integer distances
	count := 0

	// Iterate over all pairs of points
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			// Check if the distance between the two points is an integer
			if dist(points[i], points[j]).IsInt() {
				count++
			}
		}
	}

	// Print the total count of pairs with integer distances
	fmt.Println(count)
}

