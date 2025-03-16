

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
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Input the elements and create a list of tuples
	A := make([][]int, N)
	for i, x := range strings.Split(bufio.NewReader(os.Stdin).Scan(), " ") {
		A[i] = []int{i + 1, strconv.Atoi(x)}
	}

	// Sort the list of tuples based on the integer values
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the indices from the sorted list of tuples
	A_ := make([]int, N)
	for i, a := range A {
		A_[i] = a[0]
	}

	// Print the indices in the required format
	for i, a := range A_[:N-1] {
		fmt.Printf("%d ", a)
	}
	fmt.Println(A_[N-1])
}
