package main

import (
	"fmt"
	"math"
)

func main() {
	// Step 1: Read the number of points N from the input.
	var N int
	fmt.Scan(&N)
	
	// Step 2: Read the coordinates of each point and store them in arrays x and y.
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}
	
	// Step 3: For each point, calculate the angles between this point and all other points.
	for i := 0; i < N; i++ {
		thetas := []float64{}
		for j := 0; j < N; j++ {
			if i == j {
				continue // Skip the point itself
			}
			// Calculate the angle using atan2
			theta := math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i]))
			thetas = append(thetas, theta)
		}
		
		// Step 4: Sort the angles and add 2π to the last angle to handle the wrap-around.
		sort.Float64s(thetas)
		thetas = append(thetas, thetas[0] + 2 * math.Pi)
		
		// Step 5: Find the maximum difference between consecutive angles, subtract π, and divide by 2π to get the fraction of the circle.
		ans := 0.0
		for k := 0; k < N - 1; k++ {
			diff := thetas[k+1] - thetas[k] - math.Pi
			if diff > ans {
				ans = diff
			}
		}
		
		// Step 6: Print the result.
		fmt.Println(ans / (math.Pi * 2))
	}
}
