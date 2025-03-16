
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Comparator function for sort.Ints to sort the array tomatu
func miyukiti(i, j int) bool {
	return A[i] < A[j]
}

// Number of elements
var N int
// Array of elements
var A []int

// Number of unique elements
var yukinnko int
// Array to store unique elements
var tomatu []int

// Array to store boolean values
var mikakosi []bool

// Function to perform binary search to find the index of an element in the sorted array tomatu
func sumipe(hayaminn int) int {
	satorina, zaasan := 0, yukinnko-1
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
	var inorinn int
	var emirinn int
	// Read the number of elements N from the input
	N = readInt()
	// Read the array A from the input and simultaneously copy it to tomatu
	A = make([]int, N)
	tomatu = make([]int, N)
	copy(tomatu, A)
	// Sort the array tomatu using the comparator function miyukiti
	sort.Ints(tomatu)
	// Initialize yukinnko to 1 and store unique elements in tomatu
	yukinnko = 1
	for inorinn = 1; inorinn < N; inorinn++ {
		if tomatu[inorinn]!= tomatu[yukinnko-1] {
			tomatu[yukinnko] = tomatu[inorinn]
			yukinnko++
		}
	}
	// Initialize mikakosi to all false
	mikakosi = make([]bool, yukinnko)
	// Iterate over the array A, use sumipe to find the index, and toggle mikakosi
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu := sumipe(A[inorinn])
		mikakosi[kugyu] =!mikakosi[kugyu]
	}
	// Count and print the number of elements in mikakosi that are true
	for inorinn = 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] {
			emirinn++
		}
	}
	fmt.Println(emirinn)
}

func readInt() int {
	var inorinn int
	_, err := fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &inorinn)
	if err!= nil {
		panic(err)
	}
	return inorinn
}

