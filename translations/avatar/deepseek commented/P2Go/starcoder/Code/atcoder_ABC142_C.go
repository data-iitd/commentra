
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Input the number of elements (N)
	var N int
	fmt.Scanf("%d\n", &N)

	// Input the elements and create a list of tuples
	var A [][2]int
	for i := 0; i < N; i++ {
		var x int
		fmt.Scanf("%d", &x)
		A = append(A, [2]int{i + 1, x})
	}

	// Sort the list of tuples based on the integer values
	sort.Slice(A, func(i, j int) bool { return A[i][1] < A[j][1] })

	// Extract the indices from the sorted list of tuples
	var A_ []int
	for _, a := range A {
		A_ = append(A_, a[0])
	}

	// Print the indices in the required format
	for i := 0; i < len(A_) - 1; i++ {
		fmt.Printf("%d ", A_[i])
	}
	fmt.Printf("%d\n", A_[len(A_) - 1])
}

