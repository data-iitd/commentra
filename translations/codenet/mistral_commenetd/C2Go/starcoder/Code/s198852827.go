
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// ABS returns the absolute value of a number
func ABS(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	// Read the number of test cases
	N, _ := strconv.Atoi(readLine())

	// Loop through each test case
	for i := 0; i < N; i++ {
		// Read the current test case data (t, x, y)
		t, _ := strconv.Atoi(readLine())
		x, _ := strconv.Atoi(readLine())
		y, _ := strconv.Atoi(readLine())

		// Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
		tmp := t - nt - (ABS(x-nx) + ABS(y-ny))

		// Check if the current test case satisfies the condition
		if tmp < 0 || tmp%2!= 0 {
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

