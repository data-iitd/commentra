

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	graph := make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, 0)
	}

	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		a--
		b--
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}

	var maxMatching int
	for i := 0; i < n; i++ {
		maxMatching += len(graph[i]) / 2
	}

	if maxMatching*2 == n {
		fmt.Fprintln(writer, "Second")
	} else {
		fmt.Fprintln(writer, "First")
	}

	writer.Flush()
}

These comments should provide a clear understanding of the code for anyone who reads it.

