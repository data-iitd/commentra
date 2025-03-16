package main

import (
	"fmt"
)

// Global arrays for storing results and prime information
var kekka [2]int // Array to store the result of factorization
var prime_or_not [1001]int // Array to mark prime numbers
var prime_list [1001]int // List to store prime numbers
var prime_num [1001]int // Array to store the count of prime factors for each prime
var prime_counter int = 0 // Counter for the number of primes found

// Function to find all prime numbers up to 1000 using the Sieve of Eratosthenes
func sosuubunnpu() {
	// Initialize the prime_or_not array to 0 (indicating all numbers are initially assumed prime)
	for i := 1; i <= 1000; i++ {
		prime_or_not[i] = 0
	}

	// Mark non-prime numbers in the prime_or_not array
	for i := 2; i <= 1000; i++ {
		for j := 2; j <= 1000 / i; j++ {
			if prime_or_not[i] == 0 { // If i is still marked as prime
				prime_or_not[i * j] = 1 // Mark multiples of i as non-prime
			}
		}
	}

	// Populate the prime_list with the actual prime numbers found
	for i := 2; i <= 1000; i++ {
		if prime_or_not[i] == 0 { // If i is prime
			prime_list[prime_counter] = i // Add to the prime list
			prime_counter += 1 // Increment the prime counter
		}
	}
}

// Function to perform prime factorization of N by dividing it by n
func innsuubunnkai(N int, n int) {
	time := 0 // Counter for how many times N can be divided by n
	for {
		if N % n == 0 { // If N is divisible by n
			N = N / n // Divide N by n
			time++ // Increment the division count
		} else {
			break // Exit loop if N is no longer divisible by n
		}
	}
	kekka[0] = time // Store the count of divisions in kekka[0]
	kekka[1] = N // Store the remaining value of N in kekka[1]
}

func main() {
	// Generate the list of prime numbers
	sosuubunnpu()

	var N int // Variable to store the input number
	fmt.Scan(&N) // Read the input number from the user
	var innsuu [11]int // Array to store counts of prime factors (up to 10 different primes)
	var A [N + 1][11]int // 2D array to store factorization results (not used in the provided code)

	// Initialize the prime_num array to 0
	for i := 0; i <= 1000; i++ {
		prime_num[i] = 0
	}

	var result int = 1 // Variable to store the final result

	// Loop through each number from 2 to N to factorize it
	for current_num := 2; current_num <= N; current_num++ {
		kekka[1] = current_num // Set the current number to factorize
		for i := 0; i < prime_counter; i++ {
			innsuubunnkai(kekka[1], prime_list[i]) // Factorize current_num by each prime
			prime_num[i] += kekka[0] // Update the count of prime factors for the prime
		}
	}

	// Accumulate the counts of prime factors for each prime
	for current_num := 2; current_num <= N; current_num++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[current_num][i] // This line seems to be incomplete or unused
		}
	}

	// Calculate the final result based on the counts of prime factors
	for i := 0; i < prime_counter; i++ {
		result = (result * (prime_num[i] + 1)) % 1000000007 // Update result with the formula
	}

	// Output the final result
	fmt.Println(result)

	// End of the program
	fmt.Println("