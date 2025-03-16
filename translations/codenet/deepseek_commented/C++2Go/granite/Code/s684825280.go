
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const SIZE = (1e5 * 2) + 13

var a []int
var cnt [SIZE]int

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, k int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	// Count occurrences of each integer
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscanf(reader, "%d", &x)
		cnt[x]++
	}

	// Filter non-zero counts and store them in vector a
	for i := 0; i < SIZE; i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i])
		}
	}

	// Sort the vector a in ascending order
	sort.Ints(a)

	// Calculate the sum of the smallest k counts in vector a
	ans := 0
	m := len(a) - k
	for i := 0; i < m; i++ {
		ans += a[i]
	}

	// Output the result
	fmt.Println(ans)
}

