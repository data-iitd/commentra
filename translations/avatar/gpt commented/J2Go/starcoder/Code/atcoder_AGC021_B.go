package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of points N
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	// Initialize arrays to store the x and y coordinates of the points
	x := make([]int, N)
	y := make([]int, N)

	// Read the coordinates of the points from user input
	for i := 0; i < N; i++ {
		scanner.Scan()
		xy := strings.Split(scanner.Text(), " ")
		x[i], _ = strconv.Atoi(xy[0])
		y[i], _ = strconv.Atoi(xy[1])
	}

	// Iterate over each point to calculate the angles with respect to other points
	for i := 0; i < N; i++ {
		// Create a list to store the angles (thetas) for the current point
		thetas := make([]float64, 0)

		// Calculate the angle between the current point and all other points
		for j := 0; j < N; j++ {
			// Skip the current point itself
			if i == j {
				continue
			}

			// Calculate the angle using atan2 and add it to the list
			thetas = append(thetas, math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i])))
		}

		// Sort the angles in ascending order
		sort.Float64s(thetas)

		// Add the angle that wraps around (2 * PI) to handle circularity
		thetas = append(thetas, thetas[0]+2*math.Pi)

		// Initialize a variable to find the maximum angle difference
		ans := 0.0

		// Calculate the maximum angle difference between consecutive angles
		for k := 0; k < N-1; k++ {
			ans = math.Max(ans, thetas[k+1]-thetas[k]-math.Pi)
		}

		// Output the result as a fraction of the full circle (2 * PI)
		fmt.Println(ans / (math.Pi * 2))
	}
}

