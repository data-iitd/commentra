package main

import (
	"fmt"
)

var (
	kekka         [2]int           // Array to store the result of factorization
	primeOrNot    [1001]int        // Array to mark prime numbers
	primeList     [1001]int        // List to store prime numbers
	primeNum      [1001]int        // Array to store the count of prime factors for each prime
	primeCounter   int              // Counter for the number of primes found
)

// Function to find all prime numbers up to 1000 using the Sieve of Eratosthenes
func sosuubunnpu() {
	// Initialize the primeOrNot array to 0 (indicating all numbers are initially assumed prime)
	for i := 1; i <= 1000; i++ {
		primeOrNot[i] = 0
	}

	// Mark non-prime numbers in the primeOrNot array
	for i := 2; i <= 1000; i++ {
		for j := 2; j <= 1000/i; j++ {
			if primeOrNot[i] == 0 { // If i is still marked as prime
				primeOrNot[i*j] = 1 // Mark multiples of i as non-prime
			}
		}
	}

	// Populate the primeList with the actual prime numbers found
	for i := 2; i <= 1000; i++ {
		if primeOrNot[i] == 0 { // If i is prime
			primeList[primeCounter] = i // Add to the prime list
			primeCounter++               // Increment the prime counter
		}
	}
}

// Function to perform prime factorization of N by dividing it by n
func innsuubunnkai(N, n int) {
	time := 0 // Counter for how many times N can be divided by n
	for {
		if N%n == 0 { // If N is divisible by n
			N = N / n // Divide N by n
			time++    // Increment the division count
		} else {
			break // Exit loop if N is no longer divisible by n
		}
	}
	kekka[0] = time // Store the count of divisions in kekka[0]
	kekka[1] = N    // Store the remaining value of N in kekka[1]
}

func main() {
	// Generate the list of prime numbers
	sosuubunnpu()

	var N int // Variable to store the input number
	fmt.Scan(&N) // Read the input number from the user
	var innsuu [11]int // Array to store counts of prime factors (up to 10 different primes)
	var A [1001][11]int // 2D array to store factorization results (not used in the provided code)

	// Initialize the primeNum array to 0
	for i := 0; i <= 1000; i++ {
		primeNum[i] = 0
	}

	result := 1 // Variable to store the final result

	// Loop through each number from 2 to N to factorize it
	for currentNum := 2; currentNum <= N; currentNum++ {
		kekka[1] = currentNum // Set the current number to factorize
		for i := 0; i < primeCounter; i++ {
			innsuubunnkai(kekka[1], primeList[i]) // Factorize currentNum by each prime
			primeNum[i] += kekka[0] // Update the count of prime factors for the prime
		}
	}

	// Accumulate the counts of prime factors for each prime
	for currentNum := 2; currentNum <= N; currentNum++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[currentNum][i] // This line seems to be incomplete or unused
		}
	}

	// Calculate the final result based on the counts of prime factors
	for i := 0; i < primeCounter; i++ {
		result = (result * (primeNum[i] + 1)) % 1000000007 // Update result with the formula
	}

	// Output the final result
	fmt.Println(result)
}

// <END-OF-CODE>
