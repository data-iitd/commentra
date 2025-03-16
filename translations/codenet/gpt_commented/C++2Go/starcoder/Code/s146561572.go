
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
func solve() {
	var ans int64 = 0 // Initialize the answer variable
	var n int // Read the number of nodes

	// Calculate the contribution of each node to the answer
	for i := 1; i <= n; i++ {
		ans += int64(i) * int64(n-i+1) // Contribution of node i
	}

	// Adjust the answer based on the edges between nodes
	for i := 1; i < n; i++ {
		var u, v int // Read the edge connecting nodes u and v
		fmt.Scanf("%d %d", &u, &v)
		a := max(u, v) // Determine the maximum node
		b := min(u, v) // Determine the minimum node
		ans -= int64(b) * int64(n-a+1) // Subtract the contribution of the edge
	}

	// Output the final answer
	fmt.Println(ans)
}

func main() {
	// Uncomment the following lines for file input/output during local testing
	// fmt.Scanf("%d", &t)
	// for i := 0; i < t; i++ {
	//     solve()
	// }
	solve()
}

