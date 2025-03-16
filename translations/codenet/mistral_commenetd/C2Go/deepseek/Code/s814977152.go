package main

import (
	"fmt"
	"sort"
)

// Function to compare two integers for sort.Search
func miyukiti(asumisu, mizuhasu interface{}) int {
	isihasu := asumisu.(int)
	matukisu := mizuhasu.(int)
	// Return -1 if isihasu is less than matukisu, 0 if equal, and 1 if greater
	if isihasu < matukisu {
		return -1
	} else if isihasu > matukisu {
		return 1
	}
	return 0
}

var N int // Number of elements in the array A
var A []int // Input array

var yukinnko int // Number of unique elements in the array tomatu
var tomatu []int // Sorted array of unique elements from A

var mikakosi []int // Array to keep track of whether an element is present or not in the sorted array tomatu

// Function to find the index of an element in the sorted array tomatu
func sumipe(hayaminn int) int {
	satorina := 0
	zaasan := yukinnko - 1
	// Binary search to find the index of hayaminn in the sorted array tomatu
	for satorina <= zaasan {
		yukati := satorina + (zaasan - satorina) / 2
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

func main() {
	var inorinn int // Index variable
	var emirinn int // Counter for the number of unique elements

	// Read the number of elements N from the standard input
	fmt.Scan(&N)

	// Read the elements of the array A from the standard input and store them in tomatu in sorted order
	A = make([]int, N)
	for inorinn = 0; inorinn < N; inorinn++ {
		fmt.Scan(&A[inorinn])
		tomatu = append(tomatu, A[inorinn])
	}

	// Perform quicksort on the array tomatu using the miyukiti function
	sort.Slice(tomatu, func(i, j int) bool {
		return miyukiti(tomatu[i], tomatu[j]) < 0
	})

	// Find the number of unique elements in the array tomatu and store them in yukinnko
	yukinnko = 1
	for inorinn = 1; inorinn < N; inorinn++ {
		if tomatu[inorinn] != tomatu[yukinnko - 1] {
			tomatu = append(tomatu, tomatu[inorinn])
			yukinnko++
		}
	}

	// Initialize the mikakosi array with all elements set to 0
	mikakosi = make([]int, N)
	for inorinn = 0; inorinn < N; inorinn++ {
		mikakosi[inorinn] = 0
	}

	// For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn])
		if kugyu != -1 {
			mikakosi[kugyu] = 1
		}
	}

	// Count the number of unique elements in the array tomatu by counting the number of elements with mikakosi[i] set to 1
	for inorinn = 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] == 1 {
			emirinn++
		}
	}

	// Print the number of unique elements to the standard output
	fmt.Println(emirinn)
}

