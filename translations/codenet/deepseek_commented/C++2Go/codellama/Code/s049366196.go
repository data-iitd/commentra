package main

import (
	"fmt"
	"math"
)

// Function to check if a number is prime
func is_prime(x int) bool {
	for i := 2; i*i <= x; i++ { // Iterates from 2 to the square root of x
		if x%i == 0 { // Checks if x is divisible by i
			return false // Returns false if x is divisible by i
		}
	}
	return true // Returns true if no divisors are found
}

func main() {
	var N int
	fmt.Scan(&N) // Reads an integer N from standard input

	ans := 1 // Initializes the answer variable to 1
	for i := 2; i <= N; i++ { // Iterates from 2 to N
		if is_prime(i) { // Checks if the current number i is prime
			NN := N
			cnt := 0 // Initializes a counter to count the power of the prime
			for NN > 0 { // While loop to calculate the power of the prime in N
				cnt += NN / i // Adds the quotient of NN divided by i to cnt
				NN /= i // Divides NN by i
			}
			ans *= cnt + 1 // Multiplies ans by cnt+1
			ans %= 1000000007 // Takes modulo 1000000007 to prevent overflow
		}
	}

	fmt.Println(ans) // Prints the final answer
}

