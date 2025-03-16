
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int // Number of test cases
	fmt.Scan(&n) // Read the number of test cases from standard input

	for n > 0 { // Process each test case
		n-- // Decrement n

		var p, q int // Read p and q from standard input
		fmt.Scan(&p, &q)

		l := int(math.Sqrt(float64(p*p + q*q))) // Calculate the square root of p^2 + q^2

		isprime := true // Initialize isprime to true

		for i := 0; i < l; i++ { // Iterate through all possible integers x from 0 to l^2
			for j := 0; j < l; j++ {
				x := i*i + j*j // Calculate x = i^2 + j^2

				if x <= 1 { // If x is less than or equal to 1, skip to the next iteration
					continue
				}
				if x > p*p+q*q { // If x is greater than p^2 + q^2, skip to the next iteration
					continue
				}

				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 { // Check if p*i + q*j and q*i - p*j are both divisible by x
					isprime = false // If so, set isprime to false
					break // Exit the inner loop
				}
			}
		}

		fmt.Println(func() string { // Print "P" if isprime is still true, otherwise print "C"
			if isprime {
				return "P"
			}
			return "C"
		}())
	}
}

