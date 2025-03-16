
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Global slice to hold the sieve flags for prime numbers
var flag []bool

// Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
func prime(num int) {
	i, j := 0, 0
	// Initialize the flag slice with all elements set to true
	flag = make([]bool, num+1)
	for i = 2; i*i <= num; i++ {
		if flag[i] {
			// Mark all multiples of i as non-prime
			for j = 2; i*j <= num; j++ {
				flag[i*j] = false // Marking the multiple as non-prime
			}
		}
	}
}

// Main function to execute the program
func main() {
	var n, i, cnt int
	var in = bufio.NewReader(os.Stdin)

	// Generate prime numbers up to 50000
	prime(50000)

	// Infinite loop to continuously accept user input
	for {
		// Read an integer from the user
		fmt.Fscanf(in, "%d", &n)
		// Exit the loop if the input is 0
		if n == 0 {
			break
		}

		i = 2 // Start checking from the smallest prime number
		cnt = 0 // Initialize count of valid pairs

		// Check pairs of primes that sum up to n
		for i*2 <= n {
			// If both i and n-i are prime
			if!flag[i] &&!flag[n-i] {
				cnt++ // Increment the count of valid pairs
			}
			i++ // Move to the next number
		}

		// Output the count of prime pairs that sum up to n
		fmt.Println(cnt)
	}
}

