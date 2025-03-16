package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the number of test cases
	var n int
	fmt.Scan(&n)

	// Process each test case
	for n > 0 {
		n--
		var p, q int
		// Read the values of p and q
		fmt.Scan(&p, &q)

		// Calculate the length l based on the Euclidean distance from the origin
		l := int(math.Sqrt(float64(p*p + q*q)))

		// Initialize a flag to check if the current case is prime
		isprime := true

		// Check all combinations of i and j within the range [0, l)
		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				// Calculate the sum of squares of i and j
				x := i*i + j*j

				// Skip values of x that are not in the valid range
				if x <= 1 || x >= p*p+q*q {
					continue
				}

				// Check the conditions for primality based on the given formula
				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 {
					isprime = false // Set isprime to false if conditions are met
				}
			}
		}

		// Output "P" if prime, otherwise output "C"
		if isprime {
			fmt.Println("P")
		} else {
			fmt.Println("C")
		}
	}
}

