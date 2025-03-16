
package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var n int
	fmt.Scan(&n) // Read the number of integers from the standard input
	as := make([]int, n) // Create an array of size n to store the input integers
	ps := make(map[int]int) // Create a map to store the prime factors and their powers

	// Read the input integers and calculate their prime factors
	for i := 0; i < n; i++ {
		fmt.Scan(&as[i]) // Read an integer from the standard input

		ns := primeFactorize(as[i]) // Calculate the prime factors and their powers of the current integer
		for k, v := range ns { // Iterate through the map to update the powers of the prime factors
			ps[k] = max(ps[k], v) // Update the power of the current prime factor if it's greater
		}
	}

	// Calculate the answer
	x := 1 // Initialize a variable to store the product of prime factors
	for k, v := range ps { // Iterate through the map to calculate the product of prime factors
		for i := 1; i <= v; i++ { // Calculate the power of the prime factor
			x = mul(x, k) // Multiply the current product with the prime factor
		}
	}

	ans := 0 // Initialize a variable to store the answer
	for i := 0; i < n; i++ { // Iterate through the array to calculate the answer
		ans = add(ans, div(x, as[i])) // Calculate the difference between the current product and the current integer, and add it to the answer
	}

	fmt.Println(ans) // Print the answer
}

func max(a, b int) int {
	// Return the maximum of two integers
	if a > b {
		return a
	}
	return b
}

func primeFactorize(n int) map[int]int {
	// Calculate the prime factors and their powers of a given integer
	res := make(map[int]int)
	for i := 2; i*i <= n; i++ { // Iterate through the possible prime factors
		for n%i == 0 { // If the current number is divisible by the current prime factor
			n /= i // Divide the current number by the prime factor
			res[i]++ // Increment the power of the prime factor
		}
	}
	if n != 1 { // If the number is not equal to 1, it means that it has a prime factor greater than 1
		res[n]++ // Increment the power of the last prime factor
	}
	return res
}

const mod int = 1000000007

func pow(n, k int) int {
	// Calculate n raised to the power of k modulo mod
	if k == 0 {
		return 1
	} else if k%2 == 1 {
		return pow(n, k-1) * n % mod
	} else {
		t := pow(n, k/2)
		return t * t % mod
	}
}

func add(a, b int) int {
	// Return the sum of two integers modulo mod
	return (a + b) % mod
}

func sub(a, b int) int {
	// Return the difference of two integers modulo mod
	return (a + mod - b) % mod
}

func mul(a, b int) int {
	// Return the product of two integers modulo mod
	return a % mod * b % mod % mod
}

func div(a, b int) int {
	// Return the quotient of a and b modulo mod
	return mul(a, pow(b, mod-2))
}

