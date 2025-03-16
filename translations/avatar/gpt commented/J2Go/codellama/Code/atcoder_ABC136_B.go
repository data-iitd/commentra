
package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	var stdIn = new(Scanner)

	// Read an integer N from user input
	var N int
	fmt.Scan(&N)

	// Initialize count to track the number of digits in N
	var count int

	// Temporary variable to manipulate the value of N
	var temp int

	// Variable to store the final answer
	var ans int

	// Count the number of digits in N
	for temp = N; temp > 0; temp /= 10 {
		count++
	}

	// Loop through each digit position from 1 to count
	for i := 1; i <= count; i++ {
		// Check if we are at the last digit position
		if i == count {
			// If the last digit position is odd, calculate the contribution to ans
			if i%2 == 1 {
				ans += (N - int(math.Pow10(i-1)) + 1)
			}
		} else {
			// Handle contributions for positions other than the last
			if i == 1 {
				// For the first digit position, there are 9 possibilities (1-9)
				ans += 9
			} else if i%2 == 1 {
				// For odd digit positions, calculate the range of numbers
				ans += int(math.Pow10(i)) - int(math.Pow10(i-1))
			}
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

// 