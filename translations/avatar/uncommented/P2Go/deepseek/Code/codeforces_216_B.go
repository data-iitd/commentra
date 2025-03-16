package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	ints := []int{}
	for _, s := range strings.Split(line, " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}

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

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line0 := scanner.Text()
	ints0 := []int{}
	for _, s := range strings.Split(line0, " ") {
		num, _ := strconv.Atoi(s)
		ints0 = append(ints0, num)
	}
	n, m := ints0[0], ints0[1]
	g := make(map[int]map[int]bool)
	seen := make(map[int]bool)
	for i := 1; i <= n; i++ {
		g[i] = make(map[int]bool)
	}
	for i := 0; i < m; i++ {
		scanner.Scan()
		line := scanner.Text()
		ints := []int{}
		for _, s := range strings.Split(line, " ") {
			num, _ := strconv.Atoi(s)
			ints = append(ints, num)
		}
		a, b := ints[0], ints[1]
		g[a][b] = true
		g[b][a] = true
	}
	ans := 0
	for i := 1; i <= n; i++ {
		if !seen[i] {
			nodes, edges := dfs(g, seen, i)
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
				ans += 1
			}
		}
	}
	if (n-ans)%2 == 1 {
		ans += 1
	}
	fmt.Println(ans)
}

func main() {
	for {
		solve()
	}
}
