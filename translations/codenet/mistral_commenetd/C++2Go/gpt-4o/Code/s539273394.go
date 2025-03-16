package main

import (
	"fmt"
)

var (
	kekka         [2]int
	primeOrNot    [1001]int
	primeList     [1001]int
	primeCounter   int
	primeNum      [1001]int
)

func sosuubunnpu() {
	// Initialize primeOrNot[] to all zeros.
	for i := 1; i <= 1000; i++ {
		primeOrNot[i] = 0
	}
	// Mark non-prime numbers as 1 in primeOrNot[].
	for i := 2; i <= 1000; i++ {
		for j := 2; j <= 1000/i; j++ {
			if primeOrNot[i] == 0 {
				primeOrNot[i*j] = 1
			}
		}
	}
	// Store prime numbers in primeList[].
	for i := 2; i <= 1000; i++ {
		if primeOrNot[i] == 0 {
			primeList[primeCounter] = i
			primeCounter++
		}
	}
}

func innsuubunnkai(N, n int) {
	// Initialize time to 0.
	time := 0
	// Calculate the exponent of prime number n in N.
	for {
		if N%n == 0 {
			N = N / n
			time++
		} else {
			break
		}
	}
	// Store the result in kekka[].
	kekka[0] = time
	kekka[1] = N
}

func main() {
	// Call sosuubunnpu() to calculate prime numbers.
	sosuubunnpu()
	// Read the input N from the standard input.
	var N int
	fmt.Scan(&N)
	// Initialize innsuu[] and A[][] here.
	var innsuu [11]int
	var A [1001][11]int // Adjusted to a fixed size for simplicity

	// Initialize primeNum[] to zeros.
	for i := 0; i <= 1000; i++ {
		primeNum[i] = 0
	}
	// Calculate primeNum[] using innsuubunnkai().
	for currentNum := 2; currentNum <= N; currentNum++ {
		kekka[1] = currentNum
		for i := 0; i < primeCounter; i++ {
			innsuubunnkai(kekka[1], primeList[i])
			primeNum[i] += kekka[0]
		}
	}
	// Calculate the final result.
	result := uint64(1)
	for currentNum := 2; currentNum <= N; currentNum++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[currentNum][i]
		}
	}
	for i := 0; i < primeCounter; i++ {
		result = (result * uint64(primeNum[i]+1)) % 1000000007
	}
	// Output the final result.
	fmt.Println(result)
}

// <END-OF-CODE>
