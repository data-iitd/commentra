
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	n int
	g [][][]int
	ans []int
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	g = make([][][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([][]int, 0)
	}
	for i := 0; i < n-1; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		b, _ := strconv.Atoi(sc.Text())
		a--
		b--
		g[a] = append(g[a], []int{i, b})
		g[b] = append(g[b], []int{i, a})
	}
	ans = make([]int, n-1)
	dfs(0, -1, -1)
	max := 0
	for _, temp := range ans {
		if temp > max {
			max = temp
		}
	}
	fmt.Println(max)
	for _, c := range ans {
		fmt.Println(c)
	}
}

func dfs(to, color, parent int) {
	k := 1
	for _, e := range g[to] {
		if e[1] == parent {
			continue
		}
		if k == color {
			k++
		}
		ans[e[0]] = k
		dfs(e[1], k, to)
		k++
	}
}

