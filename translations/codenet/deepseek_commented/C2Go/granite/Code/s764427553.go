
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Define the maximum value for the sieve
	const MAX_V = 999999
	// Array to store prime status of numbers from 0 to MAX_V
	prime := make([]bool, MAX_V+1)
	
	// Initialize the prime array to true, indicating all numbers are potential primes
	for i := 2; i <= MAX_V; i++ {
		prime[i] = true
	}
	
	// Sieve of Eratosthenes to find prime numbers
	for i := 2; i*i <= MAX_V; i++ {
		if prime[i] {
			// If i is a prime, mark its multiples as non-prime
			for k := 2 * i; k <= MAX_V; k += i {
				prime[k] = false
			}
		}
	}
	
	// Set 0 and 1 as non-prime
	prime[0] = false
	prime[1] = false
	
	// Counter for the number of inputs processed
	count := 0
	
	// Read integers from standard input until EOF
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		count++
		n, _ := strconv.Atoi(scanner.Text())
		cnt := 0
		// Count the number of primes less than or equal to n
		for i := n; i > 0; i-- {
			if prime[i] {
				cnt++
			}
		}
		// Print the count of primes for the current input
		fmt.Println(cnt)
		// Break the loop after processing 30 inputs
		if count == 30 {
			break
		}
	}
	
	// Handle any errors that may occur during input reading
	if err := scanner.Err(); err!= nil {
		fmt.Println("Error reading input:", err)
	}
}

