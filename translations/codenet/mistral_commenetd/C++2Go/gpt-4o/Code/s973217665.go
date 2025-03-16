package main

import (
	"fmt"
	"math"
)

func main() {
	var n int // Number of test cases
	fmt.Scan(&n) // Read the number of test cases from standard input

	for n > 0 { // Process each test case
		n--

		var p, q int // Read p and q from standard input
		fmt.Scan(&p, &q)

		l := int(math.Sqrt(float64(p*p + q*q))) // Calculate the square root of p^2 + q^2

		isPrime := true // Initialize isPrime to true

		for i := 0; i < l; i++ { // Iterate through all possible integers i from 0 to l-1
			for j := 0; j < l; j++ { // Iterate through all possible integers j from 0 to l-1
				x := i*i + j*j // Calculate x = i^2 + j^2

				if x <= 1 {
					continue // If x is less than or equal to 1, skip to the next iteration
				}
				if x > p*p+q*q {
					continue // If x is greater than p^2 + q^2, skip to the next iteration
				}

				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 { // Check if p*i + q*j and q*i - p*j are both divisible by x
					isPrime = false // If so, set isPrime to false
					break // Exit the inner loop
				}
			}
			if !isPrime {
				break // Exit the outer loop if isPrime is false
			}
		}

		if isPrime {
			fmt.Println("P") // Print "P" if isPrime is still true
		} else {
			fmt.Println("C") // Otherwise print "C"
		}
	}
}

// <END-OF-CODE>
