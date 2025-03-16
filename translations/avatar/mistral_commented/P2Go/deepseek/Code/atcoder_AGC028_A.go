package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Define input variables N and M as integers
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize variables S and T as strings
	var S, T string
	fmt.Scan(&S, &T)

	// Convert strings S and T into lists
	listS := []rune(S)
	listT := []rune(T)

	// Initialize a list Number_i containing numbers from 0 to N-1
	Number_i := make([]int, N)
	for i := 0; i < N; i++ {
		Number_i[i] = i
	}

	// Initialize an empty list Number_iMN to store the results of the division i*M/N
	Number_iMN := []int{}

	// Iterate through each number i in the list Number_i
	for _, i := range Number_i {
		// Append the result of the division i*M/N to the list Number_iMN
		Number_iMN = append(Number_iMN, i*M/N)
	}

	// Initialize a list Number_j containing numbers from 0 to M-1
	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}

	// Find the common elements between Number_iMN and Number_j using set intersection
	var Kaburi_j []int
	for _, num := range Number_iMN {
		for _, j := range Number_j {
			if num == j {
				Kaburi_j = append(Kaburi_j, j)
				break
			}
		}
	}

	// Initialize an empty list Kaburi_i to store the integer representations of the common elements
	Kaburi_i := []int{}

	// Iterate through each common element j in Kaburi_j
	for _, j := range Kaburi_j {
		// Append the integer representation of j to the list Kaburi_i
		Kaburi_i = append(Kaburi_i, j*N/M)
	}

	// Initialize a counter variable to keep track of the current index in Kaburi_i
	counter := 0

	// Initialize a flag variable to indicate whether there is a mismatch between S and T
	Flag := 0

	// Determine the size of Kaburi_i
	Kaburi_Size := len(Kaburi_i)

	// Iterate through each index in Kaburi_i until the end of the list
	for counter < Kaburi_Size {
		// Check if the corresponding elements in S and T match
		if listS[Kaburi_i[counter]] != listT[Kaburi_j[counter]] {
			// Set the flag variable to 1 if there is a mismatch
			Flag = 1
			// Break out of the loop
			break
		}
		// Increment the counter variable
		counter++
	}

	// Define a function gcd(a, b) to calculate the greatest common divisor of two integers
	func gcd(a, b int) int {
		// While b is not equal to 0, keep updating a and b using the modulo operator
		for b > 0 {
			a, b = b, a % b
		}
		// Return the final value of a as the greatest common divisor
		return a
	}

	// Check if there is a mismatch between S and T
	if Flag == 1 {
		// Print -1 if there is a mismatch
		fmt.Println(-1)
	} else {
		// Calculate and print the product of N and M divided by their greatest common divisor
		fmt.Println(N * M / gcd(N, M))
	}
}
