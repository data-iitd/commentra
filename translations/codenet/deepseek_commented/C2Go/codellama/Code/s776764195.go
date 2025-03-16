package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input into the buffer
	str, _ := ioutil.ReadAll(os.Stdin)

	// Get the number of elements
	n, _ := strconv.Atoi(strings.Fields(string(str))[0])

	// Read each element into the array A
	A := make([]int, n+1)
	for i := 1; i <= n; i++ {
		A[i], _ = strconv.Atoi(strings.Fields(string(str))[i])
	}

	// Sort the array A using Counting Sort
	B := make([]int, n+1)
	CountingSort(A, B, n)

	// Write each sorted element
	for i := 1; i <= n; i++ {
		fmt.Printf("%d ", B[i])
	}
	fmt.Println()
}

func CountingSort(A, B []int, n int) {
	// Initialize count array
	C := make([]int, n+1)

	// Count occurrences of each element
	for j := 1; j <= n; j++ {
		C[A[j]]++
	}

	// Calculate cumulative count
	for i := 1; i <= n; i++ {
		C[i] += C[i-1]
	}

	// Place elements in sorted order
	for j := n; j > 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]]--
	}
}

