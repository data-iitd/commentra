<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n int
		s []int
		q int
		t int
		count int = 0
	)

	// Read the number of elements
	fmt.Scanf("%d", &n)

	// Read the elements into the array s
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &s[i])
	}

	// Read the number of queries
	fmt.Scanf("%d", &q)

	// Perform a linear search for each query
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &t)
		if linersearch(s, n, t) {
			count++
		}
	}

	// Print the total count of successful searches
	fmt.Printf("%d\n", count)
}

func linersearch(a []int, n int, key int) bool {
	var i int = 0

	// Modify the array to facilitate the search
	a[n] = key

	// Perform the linear search
	for a[i]!= key {
		i++
	}

	// Return true if the key is found, false otherwise
	return i!= n
}

