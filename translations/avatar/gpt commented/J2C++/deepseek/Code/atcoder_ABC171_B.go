package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements (n) and the number of smallest elements to sum (k)
	var n, k int
	fmt.Fscan(reader, &n, &k)

	// Initialize an array to hold the input numbers
	a := make([]int, n)

	// Read n integers from input and store them in the array
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	// Sort the array in ascending order
	sort.Ints(a)

	// Initialize a variable to hold the sum of the smallest k elements
	ans := 0

	// Sum the first k elements of the sorted array
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	// Output the result (sum of the smallest k elements)
	fmt.Fprintln(writer, ans)
}
