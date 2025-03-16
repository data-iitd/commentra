package main

import (
	"fmt"
	"math"
)

func main() {
	// Reading the first long integer input N
	var N int64
	fmt.Scan(&N)

	// Initializing the minimum long integer variable with the first input value
	var min int64
	for i := 0; i < 5; i++ {
		var input int64
		fmt.Scan(&input) // Read the input value
		if i == 0 {      // If it's the first iteration of the loop
			min = input  // Set the minimum value to the current input value
		} else {        // Otherwise
			if input < min {
				min = input // Update the minimum value if the current input is smaller
			}
		}
	}

	// Printing the answer
	p(int64(math.Ceil(float64(N)/float64(min))) + 4)
}

// Utility method to print a long integer as output
func p(ans int64) {
	fmt.Println(ans)
}

// Utility method to print an integer as output
func pInt(ans int) {
	fmt.Println(ans)
}

// Utility method to print nothing as output
func pVoid() {
	fmt.Println()
}

// Utility method to print a double as output
func pDouble(ans float64) {
	fmt.Println(ans)
}

// Utility method to print a string as output
func pString(ans string) {
	fmt.Println(ans)
}
