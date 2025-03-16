

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of vertices from the input
	n, _ := fmt.Fscanf(reader, "%d\n", &n)

	// Initialize an answer vector of size n
	ans := make([]int, n)

	// Read the edges and increment the count of each vertex in the answer vector
	for i := 0; i < n-1; i++ {
		a, _ := fmt.Fscanf(reader, "%d\n", &a)
		a-- // Decrement the vertex index as it is 0-indexed
		ans[a]++ // Increment the count of the vertex
	}

	// Print the answer vector
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

