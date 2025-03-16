package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// readInts reads a line of input and returns a slice of integers.
func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// dfs performs a depth-first search to count nodes and edges in a graph.
func dfs(g map[int]map[int]bool, seen map[int]bool, i int) (int, int) {
	if seen[i] {
		return 0, 0
	}
	seen[i] = true
	nodes := 1
	edges := len(g[i])
	for j := range g[i] {
		x, y := dfs(g, seen, j)
		nodes += x
		edges += y
	}
	return nodes, edges
}

// solve is the main function to solve the problem.
func solve() bool {
	line0 := readInts()
	if len(line0) == 0 {
		return false
	}
	n, m := line0[0], line0[1]
	g := make(map[int]map[int]bool)
	seen := make(map[int]bool)
	for i := 1; i <= n; i++ {
		g[i] = make(map[int]bool)
	}
	for i := 0; i < m; i++ {
		a, b := readInts()[0], readInts()[1]
		g[a][b] = true
		g[b][a] = true
	}
	ans := 0
	for i := 1; i <= n; i++ {
		if !seen[i] {
			nodes, edges := dfs(g, seen, i)
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
				ans++
			}
		}
	}
	if (n-ans)%2 == 1 {
		ans++
	}
	fmt.Println(ans)
	return true
}

func main() {
	for solve() {
	}
}

