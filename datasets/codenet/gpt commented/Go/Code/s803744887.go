package main

import "fmt"

func main() {
	// Define a constant for the maximum limit for the sieve
	const MX = 10000
	
	// Create a slice to hold the sieve values and a slice to store the prime numbers
	sieve := make([]int, MX)
	primes := make([]int, 0, MX)
	
	// Implement the Sieve of Eratosthenes to find all prime numbers up to MX
	for i := 2; i < MX; i++ {
		// If sieve[i] is not zero, it means i is not a prime number
		if sieve[i] != 0 {
			continue
		}
		// i is a prime number, add it to the primes slice
		primes = append(primes, i)
		// Mark all multiples of i as non-prime by setting their sieve value
		for j := i + i; j < MX; j += i {
			sieve[j] = i
		}
	}

	// Read the number of integers to process
	var n int
	fmt.Scan(&n)
	
	// Initialize a counter for the number of integers that are prime
	ans := 0
	
	// Process each integer input
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		// Assume the number is prime initially
		ans++
		// Check if x is divisible by any of the found prime numbers
		for j := 0; j < len(primes); j++ {
			// If x is greater than the prime and divisible by it, it's not prime
			if x > primes[j] && x%primes[j] == 0 {
				ans-- // Decrease the count of prime numbers
				break // No need to check further primes
			}
		}
	}
	
	// Output the count of prime numbers found
	fmt.Println(ans)
}
