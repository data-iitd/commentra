

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Function to compare two integers for sort.Ints
func miyukiti(a, b int) bool {
	return a < b
}

func main() {
	var N int
	var A []int
	var yukinnko int
	var tomatu []int
	var mikakosi []int

	// Read the number of elements N from the standard input
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &N)

	// Read the elements of the array A from the standard input and store them in tomatu in sorted order
	A = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &A[i])
		tomatu = append(tomatu, A[i])
	}

	// Perform sort.Ints on the array tomatu using the miyukiti function
	sort.Ints(tomatu)

	// Find the number of unique elements in the array tomatu and store them in yukinnko
	yukinnko = 1
	for i := 1; i < N; i++ {
		if tomatu[i]!= tomatu[yukinnko-1] {
			tomatu = append(tomatu, tomatu[i])
			yukinnko++
		}
	}

	// Initialize the mikakosi array with all elements set to 0
	mikakosi = make([]int, N)

	// For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
	for i := 0; i < N; i++ {
		index := sort.SearchInts(tomatu, A[i])
		mikakosi[index] = 1
	}

	// Count the number of unique elements in the array tomatu by counting the number of elements with mikakosi[i] set to 1
	emirinn := 0
	for i := 0; i < yukinnko; i++ {
		if mikakosi[i] == 1 {
			emirinn++
		}
	}

	// Print the number of unique elements to the standard output
	fmt.Println(emirinn)
}

