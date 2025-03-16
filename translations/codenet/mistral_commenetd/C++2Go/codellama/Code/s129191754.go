
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements in the vector
	var n int
	fmt.Scan(&n)

	// Initialize a vector of size n with default-constructed elements
	a := make([]int, n)

	// Read the elements of the vector
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the vector in ascending order
	sort.Ints(a)

	// Check if there are any consecutive elements in the sorted vector
	for i := 0; i < n-1; i++ {
		// If there are consecutive elements, print "NO" and exit the program
		if a[i] == a[i+1] {
			fmt.Println("NO")
			return
		}
	}

	// If no consecutive elements were found, print "YES"
	fmt.Println("YES")
}

