package main

import (
	"fmt"
	"math"
)

// Global pointer to hold the sieve flags for prime numbers
var flag []int

// Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
func prime(num int) {
	var i, j int

	// Allocate memory for the flag array to mark non-prime numbers
	flag = make([]int, num+1)

	// Implementing the Sieve of Eratosthenes
	for i = 2; i*i <= num; i++ {
		// If the number is still marked as prime
		if flag[i] == 0 {
			// Mark all multiples of i as non-prime
			for j = 2; i*j <= num; j++ {
				flag[i*j] = 1 // Marking the multiple as non-prime
			}
		}
	}
}

// Main function to execute the program
func main() {
	var n, i, cnt int

	// Generate prime numbers up to 50000
	prime(50000)

	// Infinite loop to continuously accept user input
	for {
		// Read an integer from the user
		fmt.Scan(&n)
		// Exit the loop if the input is 0
		if n == 0 {
			break
		}

		i = 2 // Start checking from the smallest prime number
		cnt = 0 // Initialize count of valid pairs

		// Check pairs of primes that sum up to n
		for i*2 <= n {
			// If both i and n-i are prime
			if flag[i] == 0 && flag[n-i] == 0 {
				cnt++ // Increment the count of valid pairs
			}
			i++ // Move to the next number
		}

		// Output the count of prime pairs that sum up to n
		fmt.Println(cnt)
	}
}

