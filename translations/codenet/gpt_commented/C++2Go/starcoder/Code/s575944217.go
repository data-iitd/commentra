package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define constants for maximum vertices and modulo value
const MAX_V = 100001
const MOD = 1000000007

// Define a type for a graph represented as an adjacency list
type Graph [][]int

func main() {
	// Read the number of vertices (or nodes)
	var n int
	fmt.Scanf("%d\n", &n)

	// Initialize a vector to store the count of edges for each vertex
	ans := make([]int, n)

	// Read n-1 edges and count the occurrences for each vertex
	for i := 0; i < n-1; i++ {
		var a int
		fmt.Scanf("%d\n", &a)
		a--
		ans[a]++
	}

	// Output the count of edges for each vertex
	for i := 0; i < n; i++ {
		fmt.Printf("%d\n", ans[i])
	}
}

