package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of test cases
	for n > 0 {
		n--
		var p, q int
		fmt.Scan(&p, &q) // Read the values of p and q for each test case
		l := int(math.Sqrt(float64(p*p + q*q))) // Calculate the length of the hypotenuse
		isPrime := true // Initialize a flag to check if the number is prime

		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ { // Loop through all pairs (i, j) within the range of l
				x := i*i + j*j // Calculate the sum of squares
				if x <= 1 || x >= p*p+q*q {
					continue // Skip if x is out of range
				}
				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 {
					isPrime = false // Check the conditions
				}
			}
		}
		if isPrime {
			fmt.Println("P") // Print "P" if prime
		} else {
			fmt.Println("C") // Print "C" if composite
		}
	}
}

// <END-OF-CODE>
