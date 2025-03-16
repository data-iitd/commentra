
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var N int
	var count int
	var temp int
	var ans int

	// Read the integer N from standard input
	fmt.Scan(&N)

	// Initialize a counter to count the number of digits in N
	count = 0

	// Initialize a temporary variable to hold the value of N
	temp = N

	// Initialize a variable to accumulate the result
	ans = 0

	// Calculate the number of digits in N
	for temp > 0 {
		temp /= 10
		count++
	}

	// Iterate from 1 to the number of digits in N
	for i := 1; i <= count; i++ {
		if i == count { // Check if it's the last digit
			if i%2 == 1 { // Check if the position is odd
				ans += (N - int(math.Pow10(i-1)) + 1)
			}
		} else {
			if i == 1 { // Check if it's the first digit
				ans += 9
			} else if i%2 == 1 { // Check if the position is odd
				ans += (int(math.Pow10(i)) - int(math.Pow10(i-1)))
			}
		}
	}

	fmt.Println(ans) // Print the result
}

