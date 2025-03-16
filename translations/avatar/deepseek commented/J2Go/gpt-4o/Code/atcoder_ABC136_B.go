package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the integer N from standard input
	count := 0   // Initialize a counter to count the number of digits in N
	temp := N    // Initialize a temporary variable to hold the value of N
	ans := 0     // Initialize a variable to accumulate the result

	// Calculate the number of digits in N
	for temp > 0 {
		temp /= 10
		count++
	}

	// Iterate from 1 to the number of digits in N
	for i := 1; i <= count; i++ {
		if i == count { // Check if it's the last digit
			if i%2 == 1 { // Check if the position is odd
				ans += (N - int(math.Pow(10, float64(i-1))) + 1) // Add the count of numbers with odd positions
			}
		} else {
			if i == 1 { // Check if it's the first digit
				ans += 9 // Add the count of single-digit numbers
			} else if i%2 == 1 { // Check if the position is odd
				ans += (int(math.Pow(10, float64(i))) - int(math.Pow(10, float64(i-1)))) // Add the count of numbers in odd positions
			}
		}
	}

	fmt.Println(ans) // Print the result
}

// <END-OF-CODE>
