

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Main function starts here
func main() {
	// Initialize an array 'prime' of size MAX_V+1 with all elements set to 1
	const MAX_V = 999999
	prime := make([]int, MAX_V+1)
	for i := 0; i <= MAX_V; i++ {
		prime[i] = 1 // Initialize all elements to 1
	}

	// Sieve of Eratosthenes algorithm to find prime numbers
	for i := 2; i <= MAX_V; i++ {
		// If i is prime, mark all its multiples as composite
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
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Increment the counter for each test case
		count++

		// Convert the input test case to an integer
		n, _ := strconv.Atoi(scanner.Text())

		// Initialize a counter 'cnt' to count the number of prime digits in n
		cnt := 0

		// Iterate through each digit of n from right to left and count the number of prime digits
		for i := n; i > 0; i /= 10 {
			if prime[i%10] == 1 {
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

	// Return 0 to indicate successful execution of the program
	return
}

Translate the above Go code to Python and end with comment "