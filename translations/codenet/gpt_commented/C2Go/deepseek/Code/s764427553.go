package main

import (
	"fmt"
)

func main() {
	// Define a constant for the maximum value to check for primes
	const MAX_V = 999999
	
	// Array to hold the prime status of numbers from 0 to MAX_V
	prime := make([]bool, MAX_V + 1)
	
	// Initialize the prime array; assume all numbers are prime initially
	for i := 2; i <= MAX_V; i++ {
		prime[i] = true
	}
	
	// Implement the Sieve of Eratosthenes algorithm to find all primes up to MAX_V
	for i := 2; i * i <= MAX_V; i++ {
		if prime[i] {
			// Mark all multiples of i as non-prime
			for k := 2 * i; k <= MAX_V; k += i {
				prime[k] = false
			}
		}
	}
	
	// Explicitly mark 0 and 1 as non-prime
	prime[0] = false
	prime[1] = false
	
	// Variable to count the number of inputs processed
	count := 0
	
	// Read integers from standard input until EOF
	for {
		var n int
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}
		count++
		cnt := 0
		
		// Count how many primes are less than or equal to n
		for i := n; i > 0; i-- {
			if prime[i] {
				cnt++
			}
		}
		
		// Output the count of primes found
		fmt.Println(cnt)
		
		// Stop processing after 30 numbers
		if count == 30 {
			break
		}
	}
}

