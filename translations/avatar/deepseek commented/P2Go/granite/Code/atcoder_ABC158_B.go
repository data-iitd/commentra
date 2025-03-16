
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	read  = bufio.NewReader(os.Stdin)
	write = bufio.NewWriter(os.Stdout)
)

func main() {
	const mod = 1e9 + 7 // Modulo value
	var n, a, b int
	fmt.Fscanf(read, "%d%d%d\n", &n, &a, &b)
	ans := 0 // Initialize the result variable

	// Calculate the number of complete cycles of A + B within N
	rep := n / (a + b)

	// Update the result with the number of complete cycles multiplied by A
	ans += rep * a

	// Calculate the remaining days after the complete cycles
	res := n - rep*(a+b)

	// Update the result with the minimum of the remaining days and A
	ans += min(res, a)

	// Print the final result
	fmt.Fprintf(write, "%d\n", ans)
	write.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

