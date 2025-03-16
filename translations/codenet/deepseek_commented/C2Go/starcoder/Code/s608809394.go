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
	// Read the size of the array
	n, _ := strconv.Atoi(strings.TrimSpace(os.Args[1]))
	// Declare an array of size n
	a := make([]int, n)
	// Read n integers and store them in the array a
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(os.Args[i+2]))
	}
	// Initialize t to 0, which will store the final sum of products
	t := 0
	// Outer loop to iterate over each element in the array a
	for i := 0; i < n; i++ {
		// Initialize s to 0, which will store the sum of products for the current element
		s := 0
		// Inner loop to iterate over each element in the array a, skipping the current element
		for j := 0; j < n; j++ {
			if j <= i {
				continue
			}
			// Calculate the product of the current element and the current element in the inner loop
			m := a[i] * a[j]
			// Add the product to the sum s
			s += m
		}
		// Add the sum s to the final sum t
		t += s
	}
	// Print the final sum of products
	fmt.Println(t)
}

