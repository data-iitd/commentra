package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Create an instance of TaskD and solve the problem
	solver := TaskD{}
	solver.solve(reader, writer)
}

// TaskD struct containing the solve method
type TaskD struct{}

// solve method to solve the problem
func (t *TaskD) solve(reader *bufio.Reader, writer *bufio.Writer) {
	// Read the number of elements and the modulo value
	var n, m int
	fmt.Fscan(reader, &n, &m)

	// Read the array of elements
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	// Map to store the frequency of remainders
	dp := make(map[int]int)

	// Initialize the answer and base variable
	var ans int64 = 0
	base := 0

	// Iterate through the array to calculate the answer
	for i := 0; i < n; i++ {
		// Update the base variable
		base = (base - a[i]%m + m) % m

		// Update the frequency of remainders in the map
		dp[(base+a[i])%m]++

		// Add the frequency of the current remainder to the answer
		ans += int64(dp[base])
	}

	// Print the final answer
	fmt.Fprintln(writer, ans)
}
