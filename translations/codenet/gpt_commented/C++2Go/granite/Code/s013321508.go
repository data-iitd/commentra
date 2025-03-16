
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Declare variables for the number of elements (N) and the number of operations (M)
	N, M := readInt(), readInt()

	// Initialize a slice to hold the elements, with a length of 100000
	L := make([]int, 100000)
	var l int

	// Read N integers from input and store them in the slice L
	for i := 0; i < N; i++ {
		l = readInt()
		L[i] = l
	}

	// Sort the slice L in ascending order
	sort.Ints(L)

	// Perform M operations to modify the slice L
	for i := 0; i < M; i++ {
		// Get the maximum element from the end of the sorted slice
		maxL := L[len(L)-1]

		// If the maximum element is 0, break the loop as no further operations are needed
		if maxL == 0 {
			break
		}

		// Halve the maximum element
		maxL /= 2

		// Find the position to insert the halved value in the sorted slice
		itr := sort.SearchInts(L, maxL)

		// Insert the halved value into the slice at the found position
		L = append(L[:itr], append([]int{maxL}, L[itr:]...)...)

		// Remove the last element (the original maximum) from the slice
		L = L[:len(L)-1]
	}

	// Calculate the sum of all elements in the slice L
	ans := int64(0)
	for _, v := range L {
		ans += int64(v)
	}

	// Output the final sum
	fmt.Println(ans)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

