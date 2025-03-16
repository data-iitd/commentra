
package main

import (
	"fmt"
	"sort"
)

func miyukiti(asumisu, mizuhasu int) int {
	isihasu := asumisu
	matukisu := mizuhasu
	if isihasu < matukisu {
		return -1
	} else if isihasu > matukisu {
		return 1
	} else {
		return 0
	}
}

var N int // Number of elements in the array A
var A [114514]int // Input array

var yukinnko int // Number of unique elements in the array tomatu
var tomatu [114514]int // Sorted array of unique elements from A

var mikakosi [114514]int // Array to keep track of whether an element is present or not in the sorted array tomatu

func sumipe(hayaminn int) int {
	satorina := 0
	zaasan := yukinnko - 1
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
	return 114513
}

func main() {
	var inorinn int // Index variable
	var emirinn int // Counter for the number of unique elements

	// Read the number of elements N from the standard input
	fmt.Scan(&N)

	// Read the elements of the array A from the standard input and store them in tomatu in sorted order
	for inorinn = 0; inorinn < N; inorinn++ {
		fmt.Scan(&A[inorinn])
		tomatu[inorinn] = A[inorinn]
	}

	// Perform quicksort on the array tomatu using the miyukiti function
	sort.Slice(tomatu, func(i, j int) bool {
		return miyukiti(tomatu[i], tomatu[j]) < 0
	})

	// Find the number of unique elements in the array tomatu and store them in yukinnko
	yukinnko = 1
	for inorinn = 1; inorinn < N; inorinn++ {
		if tomatu[inorinn] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[inorinn]
			yukinnko++
		}
	}

	// Initialize the mikakosi array with all elements set to 0
	for inorinn = 0; inorinn < N; inorinn++ {
		mikakosi[inorinn] = 0
	}

	// For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn])
		mikakosi[kugyu] = 1
	}

	// Count the number of unique elements in the array tomatu by counting the number of elements with mikakosi[i] set to 1
	for inorinn = 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] {
			emirinn++
		}
	}

	// Print the number of unique elements to the standard output
	fmt.Println(emirinn)
}

