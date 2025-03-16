#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort to sort the array tomatu
func miyukiti(asumisu, mizuhasu unsafe.Pointer) int {
	isihasu := *(*int)(asumisu), matukisu := *(*int)(mizuhasu)
	if isihasu < matukisu {
		return -1
	} else if isihasu > matukisu {
		return 1
	} else {
		return 0
	}
}

// Number of elements
var N int
// Array of elements
var A [114514]int

// Number of unique elements
var yukinnko int
// Array to store unique elements
var tomatu [114514]int

// Array to store boolean values
var mikakosi [114514]bool

// Function to perform binary search to find the index of an element in the sorted array tomatu
func sumipe(hayaminn int) int {
	satorina := 0
	zaasan := yukinnko - 1
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
	return 114513
}

func main() {
	var inorinn int
	var emirinn int
	// Read the number of elements N from the input
	if _, err := fmt.Scan(&N); err != nil {
		return
	}
	// Read the array A from the input and simultaneously copy it to tomatu
	for inorinn = 0; inorinn < N; inorinn++ {
		if _, err := fmt.Scan(&A[inorinn]); err != nil {
			return
		}
		tomatu[inorinn] = A[inorinn]
	}
	// Sort the array tomatu using the comparator function miyukiti
	sort.Slice(tomatu[:N], func(i, j int) bool {
		return miyukiti(&tomatu[i], &tomatu[j]) < 0
	})
	// Initialize yukinnko to 1 and store unique elements in tomatu
	yukinnko = 1
	for inorinn = 1; inorinn < N; inorinn++ {
		if tomatu[inorinn] != tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[inorinn]
			yukinnko++
		}
	}
	// Iterate over the array A, use sumipe to find the index, and toggle mikakosi
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn])
		mikakosi[kugyu] = !mikakosi[kugyu]
	}
	// Count and print the number of elements in mikakosi that are set to true
	for inorinn = 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] {
			emirinn++
		}
	}
	fmt.Println(emirinn)
}

