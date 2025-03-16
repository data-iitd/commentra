package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	fmt.Scan(&x) // Reading an integer input from the user

	// Checking if the number is even and not equal to 2
	if x != 2 && x%2 == 0 {
		x++ // Increment the number if it's even and not 2
	}

	// Starting an infinite loop
	for {
		sqrtNum := math.Sqrt(float64(x)) // Calculating the square root of the number 'x'
		i := 3 // Starting from 3 for odd numbers

		// Checking for prime numbers using trial division method
		for i <= int(sqrtNum) {
			if x%i == 0 { // Checking if the number 'x' is divisible by 'i'
				break // If it's divisible, then 'i' is a factor and the loop is broken
			}
			i += 2 // Incrementing 'i' to check the next odd number
		}

		// If 'i' is greater than the square root, then the number 'x' is prime
		if i > int(sqrtNum) {
			break // Exiting the loop
		}

		// If the loop didn't break, then the number 'x' is not prime, so we need to find the next prime number
		x += 2 // Incrementing the number by 2 to check the next odd number
	}

	// Printing the prime number found
	fmt.Println(x)
}

// <END-OF-CODE>
