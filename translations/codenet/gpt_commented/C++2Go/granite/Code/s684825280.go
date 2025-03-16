
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const SIZE = (1e5 * 2) + 13

func main() {
	// Read the number of elements (n) and the number of largest counts to keep (k)
	var n, k int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)

	// Read n integers and count their occurrences
	cnt := make([]int, SIZE)
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &x)
		cnt[x]++
	}

	// Transfer the counts of numbers that appeared at least once to vector a
	a := make([]int, 0)
	for i := 0; i < SIZE; i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i]) // Add the count to vector a
		}
	}

	// Initialize the answer variable to accumulate the result
	ans := 0
	// Sort the counts in ascending order
	sort.Ints(a)

	// Calculate the number of counts to exclude (m) based on k
	m := len(a) - k
	// Sum the counts of the smallest m elements
	for i := 0; i < m; i++ {
		ans += a[i] // Add the count to the answer
	}

	// Output the final answer
	fmt.Println(ans)
}
