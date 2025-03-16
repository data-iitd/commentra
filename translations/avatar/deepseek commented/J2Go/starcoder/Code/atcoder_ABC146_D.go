package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 0; i < n-1; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	ans := make([]int, n-1)
	dfs(g, 0, -1, -1, ans)
	max := 0
	for _, c := range ans {
		max = max + 1
		if c == 0 {
			max = max - 1
		}
	}
	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

func dfs(g [][]int, to, color, parent int, ans []int) {
	k := 1
	for _, e := range g[to] {
		if e == parent {
			continue
		}
		if k == color {
			k++
		}
		ans[e] = k
		dfs(g, e, k, to, ans)
		k++
	}
}

