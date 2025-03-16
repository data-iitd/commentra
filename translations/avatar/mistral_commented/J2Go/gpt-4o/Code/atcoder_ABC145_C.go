package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading the number of points from the user

	pos := make([][2]int, N) // Creating a slice of arrays to store the x and y coordinates of the points

	for i := 0; i < N; i++ { // Iterating through each point
		fmt.Scan(&pos[i][0], &pos[i][1]) // Reading the x and y coordinates of the point
	}

	sum := 0.0 // Initializing the sum variable to 0

	for i := 0; i < N; i++ { // Iterating through each point
		for j := 0; j < N; j++ { // Iterating through all other points except the current one
			if i == j {
				continue // Skipping the current point when comparing it with itself
			}
			sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) // Adding the distance between the current and the other point to the sum
		}
	}

	fmt.Println(sum / float64(N)) // Printing the average distance between all pairs of points
}

func dist(x1, y1, x2, y2 int) float64 { // Defining the dist function to calculate the Euclidean distance between two points
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))) // Returning the calculated distance
}

// <END-OF-CODE>
