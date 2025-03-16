package main

import (
	"fmt"
)

const mod = 1e9 + 7

// Function to check if a number is prime
func isPrime(x int64) bool {
	// Check for edge cases
	if x <= 1 {
		return false
	}
	if x == 2 {
		return true
	}

	// Check for composite numbers up to the square root of x
	for i := int64(2); i*i <= x; i++ {
		// If x is divisible by i, it's not prime
		if x%i == 0 {
			return false
		}
	}

	// If we've made it this far, x is prime
	return true
}

func main() {
	// Read the input number N
	var N int
	fmt.Scan(&N)

	// Initialize answer to 1
	ans := int64(1)

	// Iterate through all numbers from 2 to N
	for i := 2; i <= N; i++ {
		// If the number is prime, calculate its contribution to the answer
		if isPrime(int64(i)) {
			// Initialize variables for counting prime factors and total count
			NN := N
			cnt := 0

			// Count the number of occurrences of i as a factor in N
			for NN > 0 {
				// Increment the count
				cnt += NN / i

				// Update NN to the next number without the current factor
				NN /= i
			}

			// Multiply the answer by the count and update it modulo mod
			ans = (ans * int64(cnt+1)) % mod
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
