package main

import (
	"bufio"
	"fmt"
	"os"
)

type TaskD struct{}

func (t *TaskD) solve(n, m int, a []int) int64 {
	dp := make(map[int]int) // Hashmap to store intermediate results
	var ans int64 = 0        // Answer variable
	var base int = 0         // Base value for hashmap key

	// Process each element in array a
	for i := 0; i < n; i++ {
		// Update base value
		base = (base - a[i]%m + m) % m

		// Update hashmap with current base and its count
		dp[base+a[i]%m]++

		// Update answer variable
		ans += int64(dp[base])
	}

	return ans // Return the answer
}

func main() {
	reader := bufio.NewReader(os.Stdin) // Buffered reader for reading input
	writer := bufio.NewWriter(os.Stdout) // Buffered writer for writing output
	defer writer.Flush()                  // Ensure the buffer is flushed at the end

	var n, m int
	fmt.Fscan(reader, &n, &m) // Read n and m

	a := make([]int, n) // Initialize array a
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i]) // Read each element into array a
	}

	solver := TaskD{} // Initialize TaskD solver
	ans := solver.solve(n, m, a) // Solve the problem

	fmt.Fprintln(writer, ans) // Print the answer
}

// <END-OF-CODE>
