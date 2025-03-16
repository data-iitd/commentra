package main

import (
	"fmt"
	"sort"
)

// Comparison function for sort to sort integers
func miyukiti(asumisu, mizuhasu interface{}) int {
	isihasu := asumisu.(int)
	matukisu := mizuhasu.(int)
	if isihasu < matukisu {
		return -1
	} else if isihasu > matukisu {
		return 1
	}
	return 0
}

// Global variables
var N int // Number of elements
var A []int // Array to hold input elements

var yukinnko int // Count of unique elements
var tomatu []int // Array to hold sorted elements

var mikakosi []bool // Array to track occurrences of elements

// Function to perform binary search on the sorted array
func sumipe(hayaminn int) int {
	satorina := 0
	zaasan := yukinnko - 1
	for satorina <= zaasan {
		yukati := satorina + (zaasan - satorina) / 2
		if tomatu[yukati] == hayaminn {
			return yukati // Found the element
		} else if tomatu[yukati] < hayaminn {
			satorina = yukati + 1 // Search in the right half
		} else {
			zaasan = yukati - 1 // Search in the left half
		}
	}
	return len(tomatu) // Element not found
}

// Main function
func main() {
	var inorinn int // Loop variable for input
	var emirinn int // Counter for unique elements

	// Read the number of elements
	fmt.Scan(&N)

	// Allocate memory for arrays
	A = make([]int, N)
	tomatu = make([]int, N)
	mikakosi = make([]bool, N)

	// Read the elements into array A and copy to tomatu
	for inorinn = 0; inorinn < N; inorinn++ {
		fmt.Scan(&A[inorinn])
		tomatu[inorinn] = A[inorinn] // Copying input to sorted array
	}

	// Sort the array of elements
	sort.Slice(tomatu, func(i, j int) bool {
		return miyukiti(tomatu[i], tomatu[j]) < 0
	})

	// Remove duplicates from the sorted array
	yukinnko = 1
	for inorinn = 1; inorinn < N; inorinn++ {
		if tomatu[inorinn] != tomatu[yukinnko - 1] {
			tomatu[yukinnko++] = tomatu[inorinn] // Add unique element
		}
	}

	// Track occurrences of each element in the original array
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn]) // Find index of element in sorted array
		mikakosi[kugyu] = !mikakosi[kugyu] // Toggle occurrence
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
