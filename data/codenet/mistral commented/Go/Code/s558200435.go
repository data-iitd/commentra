
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize the variable 'n' to read the number of elements in the array 'a'
	var n int
	fmt.Scan(&n)

	// Create a slice 'a' of length 'n' to store the input elements
	a := make([]int, n)

	// Read 'n' elements from the standard input and store them in slice 'a'
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize an empty slice 'b' to store the unique elements
	b := make([]int, 0, n)

	// Iterate through each element 'v' in slice 'a'
	for _, v := range a {
		// Use 'sort.Search' function to find the index 'x' where 'v' should be inserted in slice 'b'
		x := sort.Search(len(b), func(i int) bool {
			return b[i] < v
		})

		// If 'x' is equal to the length of slice 'b', it means 'v' is not present in the slice, so append it
		if x == len(b) {
			b = append(b, v)
		} else {
			// Otherwise, replace the element at index 'x' in slice 'b' with 'v'
			b[x] = v
		}
	}

	// Print the length of slice 'b' as the output
	fmt.Println(len(b))

	// End of the code
}