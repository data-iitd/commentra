
package main

import (
	"fmt"
	"math"
)

func main() {
	var N int // Variable to store the number of test cases
	var t, x, y, nx, ny, nt int // Variables to store the current test case data and previous coordinates
	var i, j, k, tmp int // Loop variables

	// Read the number of test cases
	fmt.Scan(&N)

	// Loop through each test case
	for i = 0; i < N; i++ {
		// Read the current test case data (t, x, y)
		fmt.Scan(&t, &x, &y)

		// Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
		tmp = t - nt - (int(math.Abs(float64(x-nx))) + int(math.Abs(float64(y-ny))))

		// Check if the current test case satisfies the condition
		if tmp < 0 || tmp%2 != 0 {
			// If the condition is not satisfied, print 'No' and exit the program
			fmt.Println("No")
			return
		}

		// Update the previous coordinates for the next iteration
		nx = x
		ny = y
		nt = t
	}

	// If all the test cases satisfy the condition, print 'Yes'
	fmt.Println("Yes")
}

