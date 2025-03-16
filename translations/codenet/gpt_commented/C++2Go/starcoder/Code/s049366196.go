package main

import (
	"fmt"
	"math"
)

// Function to check if a number is prime
func isPrime(x int) bool {
	// Check divisibility from 2 to the square root of x
	for i := 2; i <= int(math.Sqrt(float64(x))); i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	// Read the input value N
	var N int
	fmt.Scanf("%d", &N)

	// Initialize the answer variable to 1
	ans := 1

	// Loop through all numbers from 2 to N
	for i := 2; i <= N; i++ {
		// Check if the current number i is prime
		if isPrime(i) {
			// Store the original value of N for calculations
			NN := N
			// Initialize a counter for the prime factor's exponent
			cnt := 0

			// Count the number of times i is a factor in the numbers from 1 to N
			for NN > 0 {
				cnt += NN / i
				NN /= i
			}

			// Update the answer by multiplying with the count of factors + 1
			ans *= cnt + 1
			ans %= 1000000007
		}
	}

	// Output the final result
	fmt.Println(ans)
}

