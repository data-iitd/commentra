package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	// Read an integer input from the user
	fmt.Scan(&x)

	// If x is even and not equal to 2, increment x to make it odd
	if x != 2 && x%2 == 0 {
		x++
	}

	// Infinite loop to find the next prime number
	for {
		var i int // Variable to hold the divisor
		// Calculate the square root of x for optimization
		sqrtNum := math.Sqrt(float64(x))

		// Check for factors of x from 3 to the square root of x, incrementing by 2 (to check only odd numbers)
		for i = 3; float64(i) <= sqrtNum; i += 2 {
			// If i divides x, then x is not prime
			if x%i == 0 {
				break // Exit the loop if a divisor is found
			}
		}

		// If no divisors were found, i will be greater than sqrtNum, indicating x is prime
		if float64(i) > sqrtNum {
			break // Exit the for loop as we found a prime number
		}

		// Increment x by 2 to check the next odd number
		x += 2
	}

	// Output the next prime number
	fmt.Println(x)
}

// <END-OF-CODE>
