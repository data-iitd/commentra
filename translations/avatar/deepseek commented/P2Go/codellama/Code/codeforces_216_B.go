package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInts() []int {
	var line0 []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line0 = strings.Split(scanner.Text(), " ")
	for i := 0; i < len(line0); i++ {
		line0[i], _ = strconv.Atoi(line0[i])
	}
	return line0
}

func dfs(g map[int][]int, seen map[int]bool, i int) (int, int) {
	if seen[i] {
		return 0, 0
	}
	seen[i] = true
	nodes := 1
	edges := len(g[i])
	for _, j := range g[i] {
		x, y := dfs(g, seen, j)
		nodes += x
		edges += y
	}
	return nodes, edges
}

func solve() bool {
	line0 := readInts()
	n, m := line0[0], line0[1]
	g := make(map[int][]int)
	seen := make(map[int]bool)
	for i := 1; i <= n; i++ {
		g[i] = []int{}
	}
	for i := 0; i < m; i++ {
		a, b := readInts()
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
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
	if (n - ans)%2 == 1 {
		ans++
	}
	fmt.Println(ans)
	return true
}

func main() {
	for solve() {
	}
}

