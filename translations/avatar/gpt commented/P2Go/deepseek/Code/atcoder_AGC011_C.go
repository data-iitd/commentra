package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	vis := make([]int, n+1)
	ci, cb, cc := 0, 0, 0
	g := make([][]int, n+1)

	var dfs func(int) bool
	dfs = func(x int) bool {
		stack := [][]int{{x, 1}}
		flag := true
		for len(stack) > 0 {
			u, col := stack[len(stack)-1][0], stack[len(stack)-1][1]
			stack = stack[:len(stack)-1]
			if vis[u] != 0 {
				flag = flag && (vis[u] == col)
				continue
			}
			vis[u] = col
			for _, v := range g[u] {
				stack = append(stack, []int{v, 3 - col})
			}
		}
		return flag
	}

	for i := 0; i < m; i++ {
		input, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(input), " ")
		u, _ := strconv.Atoi(parts[0])
		v, _ := strconv.Atoi(parts[1])
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	for i := 1; i <= n; i++ {
		if vis[i] == 0 {
			if len(g[i]) == 0 {
				ci++
			} else {
				if dfs(i) {
					cb++
				} else {
					cc++
				}
			}
		}
	}

	fmt.Println(ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb)
}
