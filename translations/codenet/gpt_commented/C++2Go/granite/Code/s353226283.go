
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Global variables
var (
	n, k, t int
	vec       []int
	ans       = 1000000001
)

func main() {
	// Read the number of elements (n) and the size of the subset (k)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	// Read n integers from input and store them in the vector
	vec = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &vec[i]) // Read each integer
	}

	// Sort the vector in non-decreasing order
	sort.Ints(vec)

	// Iterate through the sorted vector to find the minimum difference
	for i := 0; i+k-1 < n; i++ {
		// Calculate the difference between the maximum and minimum of the current subset of size k
		diff := vec[i+k-1] - vec[i]

		// Update the minimum difference found so far
		if diff < ans {
			ans = diff // Update ans if a smaller difference is found
		}
	}

	// Output the minimum difference found
	fmt.Println(ans)
}

