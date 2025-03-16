
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
	// Read the number of elements in the array x
	n, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 10000)))))

	// Allocate memory for array x
	x := make([]int, n)

	// Read each element of array x
	for i := 0; i < n; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 10000)))))
	}

	// Read the number of queries
	q, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 10000)))))

	// Allocate memory for array y
	y := make([]int, q)

	// Read each element of array y
	for i := 0; i < q; i++ {
		y[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 10000)))))
	}

	// Initialize sum to zero
	sum := 0

	// Check if each element of array y is present in array x and increment sum if found
	for i := 0; i < q; i++ {
		for j := 0; j < n; j++ {
			// Check if current element of y is equal to current element of x
			if y[i] == x[j] {
				// Increment sum if found
				sum = sum + 1
				// Break out of inner loop as soon as a match is found
				break
			}
		}
	}

	// Print the value of sum
	fmt.Printf("%d\n", sum)
}

