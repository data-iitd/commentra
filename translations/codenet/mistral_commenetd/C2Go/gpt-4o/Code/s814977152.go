package main

import (
	"fmt"
	"sort"
)

// Function to compare two integers for sorting
func miyukiti(a, b int) bool {
	return a < b
}

func main() {
	var N int // Number of elements in the array A
	fmt.Scan(&N)

	A := make([]int, N) // Input array
	tomatu := make([]int, N) // Sorted array of unique elements from A

	// Read the elements of the array A from the standard input
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		tomatu[i] = A[i]
	}

	// Perform quicksort on the array tomatu
	sort.Slice(tomatu, func(i, j int) bool {
		return miyukiti(tomatu[i], tomatu[j])
	})

	// Find the number of unique elements in the array tomatu
	yukinnko := 1
	for i := 1; i < N; i++ {
		if tomatu[i] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[i]
			yukinnko++
		}
	}

	mikakosi := make([]int, yukinnko) // Array to keep track of whether an element is present or not in the sorted array tomatu

	// For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
	for i := 0; i < N; i++ {
		kugyu := sumipe(tomatu, A[i], yukinnko)
		if kugyu != -1 {
			mikakosi[kugyu] = 1
		}
	}

	// Count the number of unique elements in the array tomatu
	emirinn := 0
	for i := 0; i < yukinnko; i++ {
		if mikakosi[i] == 1 {
			emirinn++
		}
	}

	// Print the number of unique elements to the standard output
	fmt.Println(emirinn)
}

// Function to find the index of an element in the sorted array tomatu
func sumipe(tomatu []int, hayaminn int, yukinnko int) int {
	satorina := 0
	zaasan := yukinnko - 1
	// Binary search to find the index of hayaminn in the sorted array tomatu
	for satorina <= zaasan {
		yukati := satorina + (zaasan-satorina)/2
		if tomatu[yukati] == hayaminn {
			return yukati
		} else if tomatu[yukati] < hayaminn {
			satorina = yukati + 1
		} else {
			zaasan = yukati - 1
		}
	}
	// Return -1 if the element is not present in the array
	return -1
}

// <END-OF-CODE>
