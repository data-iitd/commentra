
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var n, k, t int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)
	vec := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &t)
		vec[i] = t
	}
	sort.Ints(vec)
	ans := 1000000001 // Initialize the answer with a large number
	for i := 0; i+k-1 < n; i++ { // Iterate through the sorted vector
		diff := vec[i+k-1] - vec[i] // Calculate the difference between the max and min in the subarray
		if diff < ans { // Update the answer if the current difference is smaller
			ans = diff
		}
	}
	fmt.Println(ans) // Output the minimum difference
}

