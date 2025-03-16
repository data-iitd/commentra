
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Function to compare two integers for qsort
func miyukiti(asumisu, mizuhasu interface{}) int {
	isihasu := asumisu.(int)
	matukisu := mizuhasu.(int)
	// Return -1 if isihasu is less than matukisu, 0 if equal, and 1 if greater
	if isihasu < matukisu {
		return -1
	} else if isihasu > matukisu {
		return 1
	} else {
		return 0
	}
}

func main() {
	var N int
	var A []int
	var yukinnko int
	var tomatu []int
	var mikakosi []int

	// Read the number of elements N from the standard input
	fmt.Scanf("%d", &N)

	// Read the elements of the array A from the standard input and store them in tomatu in sorted order
	for i := 0; i < N; i++ {
		var inorinn int
		fmt.Scanf("%d", &inorinn)
		A = append(A, inorinn)
	}

	// Perform quicksort on the array tomatu using the miyukiti function
	sort.Slice(A, func(i, j int) bool { return A[i] < A[j] })

	// Find the number of unique elements in the array tomatu and store them in yukinnko
	yukinnko = 1
	for i := 1; i < N; i++ {
		if A[i]!= A[yukinnko-1] {
			tomatu = append(tomatu, A[i])
			yukinnko++
		}
	}

	// Initialize the mikakosi array with all elements set to 0
	mikakosi = make([]int, N)
	for i := 0; i < N; i++ {
		mikakosi[i] = 0
	}

	// For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
	for i := 0; i < N; i++ {
		kugyu := sort.Search(yukinnko, func(j int) bool { return tomatu[j] >= A[i] })
		mikakosi[kugyu] = 1
	}

	// Count the number of unique elements in the array tomatu by counting the number of elements with mikakosi[i] set to 1
	emirinn := 0
	for i := 0; i < yukinnko; i++ {
		if mikakosi[i] == 1 {
			emirinn++
		}
	}

	// Print the number of unique elements to the standard output
	fmt.Printf("%d\n", emirinn)
}

