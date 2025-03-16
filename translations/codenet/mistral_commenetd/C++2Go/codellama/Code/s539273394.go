package main

import (
	"fmt"
)

// We declare and initialize some variables and arrays here.
var kekka [2]int
var prime_or_not [1001]int
var prime_list [1001]int
var prime_counter int = 0


// This function calculates prime numbers up to 1000 and stores them in prime_list[].
func sosuubunnpu() {
	// Initialize prime_or_not[] to all zeros.
	for i := 1; i <= 1000; i++ {
		prime_or_not[i] = 0
	}
	// Mark non-prime numbers as 1 in prime_or_not[].
	for i := 2; i <= 1000; i++ {
		for j := 2; j <= 1000/i; j++ {
			if prime_or_not[i] == 0 {
				prime_or_not[i*j] = 1
			}
		}
	}
	// Store prime numbers in prime_list[].
	for i := 2; i <= 1000; i++ {
		if prime_or_not[i] == 0 {
			prime_list[prime_counter] = i
			prime_counter++
		}
	}
}


// This function calculates the exponent of a prime number in a given number.
func innsuubunnkai(N int, n int) {
	// Initialize time to 0.
	time := 0
	// Calculate the exponent of prime number n in N.
	for N%n == 0 {
		N = N / n
		time++
	}
	// Store the result in kekka[].
	kekka[0] = time
	kekka[1] = N
}


// This is the main function where we call sosuubunnpu() and perform the main calculation.
func main() {
	// Call sosuubunnpu() to calculate prime numbers.
	sosuubunnpu()
	// Read the input N from the standard input.
	var N int
	fmt.Scan(&N)
	// Initialize innsuu[] and A[] here.
	var innsuu [11]int
	var A [N+1][11]int
	// Initialize prime_num[] to zeros.
	for i := 0; i <= 1000; i++ {
		prime_num[i] = 0
	}
	// Calculate prime_num[] using innsuubunnkai().
	for current_num := 2; current_num <= N; current_num++ {
		kekka[1] = current_num
		for i := 0; i < prime_counter; i++ {
			innsuubunnkai(kekka[1], prime_list[i])
			prime_num[i] += kekka[0]
		}
	}
	// Calculate the final result.
	result := 1
	for current_num := 2; current_num <= N; current_num++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[current_num][i]
		}
	}
	for i := 0; i < prime_counter; i++ {
		result = (result * (prime_num[i] + 1)) % 1000000007
	}
	// Output the final result.
	fmt.Println(result)
}

