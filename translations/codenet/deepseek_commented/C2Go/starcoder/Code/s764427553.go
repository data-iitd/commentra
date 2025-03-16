<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the maximum value for the sieve
const MAX_V = 999999

// Array to store prime status of numbers from 0 to MAX_V
var prime [MAX_V + 1]int

func main() {
	// Initialize the prime array to 1 (true), indicating all numbers are potential primes
	for i := 2; i <= MAX_V; i++ {
		prime[i] = 1
	}

	// Sieve of Eratosthenes to find prime numbers
	for i := 2; i * i <= MAX_V; i++ {
		if prime[i] == 1 {
			// If i is a prime, mark its multiples as non-prime
			for k := 2 * i; k <= MAX_V; k += i {
				prime[k] = 0
			}
		}
	}

	// Set 0 and 1 as non-prime
	prime[0] = 0
	prime[1] = 0

	// Read integers from standard input until EOF
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Convert the input string to an integer
		n, _ := strconv.Atoi(scanner.Text())
		// Counter for the number of primes less than or equal to n
		cnt := 0
		for i := n; i > 0; i-- {
			if prime[i] == 1 {
				cnt++
			}
		}
		// Print the count of primes for the current input
		fmt.Printf("%d\n", cnt)
	}
}

