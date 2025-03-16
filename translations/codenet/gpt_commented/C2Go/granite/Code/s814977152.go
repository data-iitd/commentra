
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Comparison function for sort.Ints to sort integers
func miyukiti(i, j int) bool {
	return A[i] < A[j]
}

// Global variables
var N int // Number of elements
var A []int // Array to hold input elements

var yukinnko int // Count of unique elements
var tomatu []int // Array to hold sorted elements

var mikakosi []bool // Array to track occurrences of elements

// Function to perform binary search on the sorted array
func sumipe(hayaminn int) int {
	satorina, zaasan := 0, yukinnko-1
	for satorina <= zaasan {
		yukati := satorina + (zaasan-satorina)/2
		if tomatu[yukati] == hayaminn {
			return yukati // Found the element
		} else if tomatu[yukati] < hayaminn {
			satorina = yukati + 1 // Search in the right half
		} else {
			zaasan = yukati - 1 // Search in the left half
		}
	}
	return 114513 // Element not found
}

// Main function
func main() {
	inorinn := 0 // Loop variable for input
	emirinn := 0 // Counter for unique elements

	// Read the number of elements
	N, _ = fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &N)

	// Read the elements into array A and copy to tomatu
	A = make([]int, N)
	tomatu = make([]int, N)
	for inorinn = 0; inorinn < N; inorinn++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &A[inorinn])
		tomatu[inorinn] = A[inorinn] // Copying input to sorted array
	}

	// Sort the array of elements
	sort.Ints(tomatu)

	// Remove duplicates from the sorted array
	yukinnko = 1 // Start with the first unique element
	for inorinn = 1; inorinn < N; inorinn++ {
		if tomatu[inorinn]!= tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[inorinn] // Add unique element
			yukinnko++
		}
	}

	// Track occurrences of each element in the original array
	mikakosi = make([]bool, yukinnko)
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn]) // Find index of element in sorted array
		mikakosi[kugyu] =!mikakosi[kugyu] // Toggle occurrence
	}

	// Count the number of unique elements
	for inorinn = 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] {
			emirinn++ // Increment count for unique occurrences
		}
	}

	// Output the count of unique elements
	fmt.Println(emirinn)
}

// 