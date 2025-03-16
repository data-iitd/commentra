
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Read the number of elements from user input
	N := readInt()

	// Read the elements from user input, creating a slice of tuples (index, value)
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = []int{i + 1, readInt()}
	}

	// Sort the slice of tuples based on the second item (the value) in each tuple
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first item (the original index) from each sorted tuple into a new slice
	A_ := make([]int, N)
	for i, a := range A {
		A_[i] = a[0]
	}

	// Print the indices of the sorted values, separated by spaces
	for i := 0; i < N-1; i++ {
		fmt.Printf("%d ", A_[i]) // Print each index followed by a space
	}
	fmt.Println(A_[N-1]) // Print the last index without a trailing space
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

