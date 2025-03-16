package main

import (
	"fmt"
	"math"
)

func main() {
	var n int64
	_, err := fmt.Scan(&n) // Reading a long integer value from user input
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	// Calculating the square root of the given number
	sqrt := int64(math.Sqrt(float64(n)))

	// Initializing the answer variable to 0
	answer := 0

	// Checking for prime factors of the given number
	for i := int64(2); i <= sqrt; i++ { // Starting a for loop to check for prime factors
		count := 0 // Initializing a counter variable to count the number of occurrences of a prime factor
		for n%i == 0 { // Checking if the given number is divisible by the current prime factor
			n /= i // Dividing the given number by the current prime factor
			count++ // Incrementing the counter variable
		}

		// Calculating the contribution of the current prime factor to the answer
		for j := int64(1); count-j >= 0; j++ {
			count -= j
			answer++
		}
	}

	// Checking for the remaining prime factor (if any)
	if n > 1 {
		answer++
	}

	// Printing the result
	fmt.Println(answer)
}

// <END-OF-CODE>
