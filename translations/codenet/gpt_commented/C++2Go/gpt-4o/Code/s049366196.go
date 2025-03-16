package main

import (
	"fmt"
)

// Function to check if a number is prime
func isPrime(x int64) bool {
	if x < 2 {
		return false
	}
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return false // If divisible, not prime
		}
	}
	return true // If no divisors found, it is prime
}

func main() {
	// Read the input value N
	var N int
	fmt.Scan(&N)

	// Initialize the answer variable to 1
	var ans int64 = 1
	const mod int64 = 1e9 + 7

	// Loop through all numbers from 2 to N
	for i := 2; i <= N; i++ {
		// Check if the current number i is prime
		if isPrime(int64(i)) {
			// Store the original value of N for calculations
			NN := N
			// Initialize a counter for the prime factor's exponent
			cnt := 0

			// Count the number of times i is a factor in the numbers from 1 to N
			for NN > 0 {
				cnt += NN / i // Count multiples of i
				NN /= i       // Reduce NN by dividing by i
			}

			// Update the answer by multiplying with the count of factors + 1
			ans = (ans * int64(cnt+1)) % mod // Take modulo to prevent overflow
		}
	}

	// Output the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
