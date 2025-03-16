package main

import (
	"fmt"
)

func main() {
	const MAX_V = 999999
	prime := make([]int, MAX_V+1)

	// Initialize the prime array
	for i := 0; i <= MAX_V; i++ {
		prime[i] = 1 // Initialize all elements to 1
	}

	// Sieve of Eratosthenes algorithm to find prime numbers
	for i := 2; i <= MAX_V; i++ {
		if prime[i] == 1 {
			for k := i * i; k <= MAX_V; k += i {
				prime[k] = 0
			}
		}
	}

	// Set prime[0] and prime[1] to 0 as they are not prime numbers
	prime[0] = 0
	prime[1] = 0

	// Initialize a counter 'count' for the number of test cases
	count := 0

	// Read input test cases until end of file is reached
	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break // Break the loop if there is an error (EOF)
		}

		// Increment the counter for each test case
		count++

		// Initialize a counter 'cnt' to count the number of prime digits in n
		cnt := 0

		// Iterate through each digit of n and count the number of prime digits
		for i := n; i > 0; i /= 10 {
			digit := i % 10 // Get the last digit
			if digit >= 0 && digit <= MAX_V && prime[digit] == 1 {
				cnt++ // Increment the counter if the digit is prime
			}
		}

		// Print the result for the current test case
		fmt.Println(cnt)

		// Break the loop if the required number of test cases have been processed
		if count == 30 {
			break
		}
	}
}

// <END-OF-CODE>
