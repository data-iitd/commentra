package main

import (
	"fmt"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the input numbers and a map to store the maximum prime factors
	as := make([]int, n)
	ps := make(map[int]int)

	// Read each number and perform prime factorization
	for i := 0; i < n; i++ {
		fmt.Scan(&as[i])

		// Get the prime factors of the current number
		ns := primeFactorize(as[i])
		// Update the maximum count of each prime factor found
		for k, v := range ns {
			ps[k] = max(ps[k], v)
		}
	}

	// Calculate the product of the maximum prime factors raised to their respective powers
	x := 1
	for k, v := range ps {
		for i := 1; i <= v; i++ {
			x = mul(x, k)
		}
	}

	// Calculate the final answer by summing the results of x divided by each input number
	ans := 0
	for i := 0; i < n; i++ {
		ans = add(ans, div(x, as[i]))
	}

	// Print the final answer
	fmt.Println(ans)
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Function to perform prime factorization of a number
func primeFactorize(n int) map[int]int {
	res := make(map[int]int)
	// Check for factors from 2 up to the square root of n
	for i := 2; i*i <= n; i++ {
		// While i is a factor of n, divide n by i and count the occurrences
		for n%i == 0 {
			n /= i
			res[i]++
		}
	}
	// If n is still greater than 1, it is a prime factor itself
	if n != 1 {
		res[n]++
	}
	return res
}

// Define a constant for the modulo operation
const mod int = 1000000007

// Function to compute n raised to the power of k under modulo
func pow(n, k int) int {
	if k == 0 {
		return 1
	} else if k%2 == 1 {
		return pow(n, k-1) * n % mod
	} else {
		t := pow(n, k/2)
		return t * t % mod
	}
}

// Function to add two integers under modulo
func add(a, b int) int {
	return (a + b) % mod
}

// Function to subtract two integers under modulo
func sub(a, b int) int {
	return (a + mod - b) % mod
}

// Function to multiply two integers under modulo
func mul(a, b int) int {
	return a % mod * b % mod % mod
}

// Function to divide two integers under modulo using modular multiplicative inverse
func div(a, b int) int {
	return mul(a, pow(b, mod-2))
}
