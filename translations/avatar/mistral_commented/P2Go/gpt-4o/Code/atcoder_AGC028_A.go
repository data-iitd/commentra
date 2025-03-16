package main

import (
	"fmt"
	"math"
)

func main() {
	// Define input variables N and M as integers
	var N, M int
	fmt.Scan(&N, &M)

	// Comments: Get the dimensions N and M of the matrices S and T from user input

	// Initialize variables S and T as strings
	var S, T string
	fmt.Scan(&S)
	fmt.Scan(&T)

	// Convert strings S and T into slices of runes
	list_S := []rune(S)
	list_T := []rune(T)

	// Initialize a slice Number_i containing numbers from 0 to N-1
	Number_i := make([]int, N)
	for i := 0; i < N; i++ {
		Number_i[i] = i
	}

	// Initialize an empty slice Number_iMN to store the results of the division i*M/N
	Number_iMN := make([]int, 0)

	// Iterate through each number i in the slice Number_i
	for _, i := range Number_i {
		// Append the result of the division i*M/N to the slice Number_iMN
		Number_iMN = append(Number_iMN, int(float64(i*M)/float64(N)))
	}

	// Initialize a slice Number_j containing numbers from 0 to M-1
	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}

	// Find the common elements between Number_iMN and Number_j using a map
	Kaburi_j_map := make(map[int]struct{})
	for _, j := range Number_j {
		Kaburi_j_map[j] = struct{}{}
	}

	// Initialize an empty slice Kaburi_j to store common elements
	Kaburi_j := make([]int, 0)
	for _, num := range Number_iMN {
		if _, exists := Kaburi_j_map[num]; exists {
			Kaburi_j = append(Kaburi_j, num)
		}
	}

	// Initialize an empty slice Kaburi_i to store the integer representations of the common elements
	Kaburi_i := make([]int, 0)

	// Iterate through each common element j in Kaburi_j
	for _, j := range Kaburi_j {
		// Append the integer representation of j to the slice Kaburi_i
		Kaburi_i = append(Kaburi_i, int(float64(j*N)/float64(M)))
	}

	// Initialize a counter variable to keep track of the current index in Kaburi_i
	counter := 0

	// Initialize a flag variable to indicate whether there is a mismatch between S and T
	Flag := 0

	// Determine the size of Kaburi_i
	Kaburi_Size := len(Kaburi_i)

	// Iterate through each index in Kaburi_i until the end of the slice
	for counter < Kaburi_Size {
		// Check if the corresponding elements in S and T match
		if list_S[Kaburi_i[counter]] != list_T[Kaburi_j[counter]] {
			// Set the flag variable to 1 if there is a mismatch
			Flag = 1
			// Break out of the loop
			break
		}
		// Increment the counter variable
		counter++
	}

	// Define a function gcd(a, b) to calculate the greatest common divisor of two integers
	gcd := func(a, b int) int {
		for b > 0 {
			a, b = b, a%b
		}
		return a
	}

	// Check if there is a mismatch between S and T
	if Flag == 1 {
		// Print -1 if there is a mismatch
		fmt.Println(-1)
	} else {
		// Calculate and print the product of N and M divided by their greatest common divisor
		fmt.Println(int(N * M / gcd(N, M)))
	}
}

// <END-OF-CODE>
