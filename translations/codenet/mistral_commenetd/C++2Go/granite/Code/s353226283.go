

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Read input values for n and k
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)

	// Initialize slice'vec' with size 'n'
	vec := make([]int, n)

	// Read input values for 't' and store them in the slice'vec'
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &vec[i])
	}

	// Sort the slice'vec' in ascending order
	sort.Ints(vec)

	// Initialize variable 'ans' with a large value
	ans := 1000000001

	// Iterate through the slice with a sliding window of size 'k'
	for i := 0; i+k-1 < n; i++ {
		// Calculate the difference between the last and first element of the current window
		diff := vec[i+k-1] - vec[i]

		// Update the answer if the current difference is smaller than the previous one
		if diff < ans {
			ans = diff
		}
	}

	// Print the answer
	fmt.Println(ans)
}

