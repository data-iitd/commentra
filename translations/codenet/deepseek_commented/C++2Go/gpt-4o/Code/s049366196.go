package main

import (
	"fmt"
)

const inf = 1e9
const mod = 1e9 + 7

// Function to check if a number is prime
func isPrime(x int64) bool {
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var N int
	fmt.Scan(&N) // Reads an integer N from standard input

	ans := int64(1) // Initializes the answer variable to 1
	for i := 2; i <= N; i++ { // Iterates from 2 to N
		if isPrime(int64(i)) { // Checks if the current number i is prime
			NN := N
			cnt := 0 // Initializes a counter to count the power of the prime
			for NN > 0 { // While loop to calculate the power of the prime in N
				cnt += NN / i // Adds the quotient of NN divided by i to cnt
				NN /= i // Divides NN by i
			}
			ans *= int64(cnt + 1) // Multiplies ans by cnt+1
			ans %= mod // Takes modulo mod to prevent overflow
		}
	}

	fmt.Println(ans) // Prints the final answer
}

// <END-OF-CODE>
