package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	var S, T string
	fmt.Scan(&S)
	fmt.Scan(&T)

	// Create a slice of indices from 0 to N-1
	Number_i := make([]int, N)
	for i := 0; i < N; i++ {
		Number_i[i] = i
	}

	// Initialize a slice to store calculated indices
	Number_iMN := make([]float64, N)

	// Calculate the scaled indices based on the ratio of M to N
	for i := 0; i < N; i++ {
		Number_iMN[i] = float64(i) * float64(M) / float64(N)
	}

	// Create a slice of indices from 0 to M-1
	Number_j := make([]int, M)
	for j := 0; j < M; j++ {
		Number_j[j] = j
	}

	// Find the common indices between the scaled Number_iMN and Number_j
	Kaburi_j := make(map[int]struct{})
	for _, j := range Number_j {
		Kaburi_j[j] = struct{}{}
	}

	Kaburi_i := []int{}
	for _, scaledIndex := range Number_iMN {
		index := int(scaledIndex)
		if _, exists := Kaburi_j[index]; exists {
			Kaburi_i = append(Kaburi_i, int(scaledIndex*float64(N)/float64(M)))
		}
	}

	// Initialize a counter for iteration and a flag for mismatch detection
	counter := 0
	Flag := 0

	// Get the size of the Kaburi_i slice
	Kaburi_Size := len(Kaburi_i)

	// Check if the characters at the calculated indices in S and T match
	for counter < Kaburi_Size {
		if S[Kaburi_i[counter]] == T[Kaburi_j[counter]] {
			// Characters match, continue checking
		} else {
			Flag = 1 // Set flag if a mismatch is found
			break    // Exit the loop on mismatch
		}
		counter++ // Move to the next index
	}

	// Output the result based on the flag indicating if a mismatch was found
	if Flag == 1 {
		fmt.Println(-1) // Print -1 if there was a mismatch
	} else {
		// Print the least common multiple (LCM) of N and M
		fmt.Println(int(float64(N*M) / float64(gcd(N, M))))
	}
}

// <END-OF-CODE>
