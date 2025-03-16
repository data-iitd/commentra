package main

import (
	"fmt"
)

const MAX = 1000
const MOD = 1000000007

// Array to store the result of prime factorization
var kekka [2]int

// Array to determine if a number is prime or not (0 for prime, 1 for not prime)
var primeOrNot [MAX + 1]int

// Array to store prime numbers
var primeList [MAX + 1]int

// Array to store the power of each prime factor
var primeNum [MAX + 1]int

// Counter to keep track of the number of prime numbers found
var primeCounter int

// Function to find all prime numbers up to MAX
func sosuubunnpu() {
	// Initialize the primeOrNot array to 0 (indicating all numbers are potential primes)
	for i := 1; i <= MAX; i++ {
		primeOrNot[i] = 0
	}

	// Mark non-prime numbers using the Sieve of Eratosthenes algorithm
	for i := 2; i <= MAX; i++ {
		if primeOrNot[i] == 0 {
			for j := 2; j <= MAX/i; j++ {
				primeOrNot[i*j] = 1
			}
		}
	}

	// Collect all prime numbers into the primeList array
	for i := 2; i <= MAX; i++ {
		if primeOrNot[i] == 0 {
			primeList[primeCounter] = i
			primeCounter++
		}
	}
}

// Function to find the power of a prime factor in the factorization of a number
func innsuubunnkai(N, n int) {
	time := 0
	for {
		if N%n == 0 {
			N = N / n
			time++
		} else {
			break
		}
	}
	kekka[0] = time
	kekka[1] = N
}

func main() {
	// Call the function to find all prime numbers up to MAX
	sosuubunnpu()

	// Read the integer N
	var N int
	fmt.Scan(&N)

	// Initialize arrays to store the prime factorization of numbers up to N
	var innsuu [11]int
	var A [MAX + 1][11]int
	for i := 0; i <= MAX; i++ {
		primeNum[i] = 0
	}

	// Calculate the prime factorization of each number up to N
	result := uint64(1)
	for currentNum := 2; currentNum <= N; currentNum++ {
		kekka[1] = currentNum
		for i := 0; i < primeCounter; i++ {
			innsuubunnkai(kekka[1], primeList[i])
			primeNum[i] += kekka[0]
		}
	}

	// Sum the powers of each prime factor for all numbers up to N
	for currentNum := 2; currentNum <= N; currentNum++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[currentNum][i]
		}
	}

	// Calculate the result using the formula for the number of divisors
	for i := 0; i < primeCounter; i++ {
		result = (result * uint64(primeNum[i]+1)) % MOD
	}

	// Print the final result
	fmt.Println(result)
}

// <END-OF-CODE>
