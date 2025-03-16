
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	var u int
	scanner.Scan()
	u, _ = strconv.Atoi(scanner.Text())
	var v int
	scanner.Scan()
	v, _ = strconv.Atoi(scanner.Text())
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}
	for i := 0; i < N-1; i++ {
		var a int
		scanner.Scan()
		a, _ = strconv.Atoi(scanner.Text())
		var b int
		scanner.Scan()
		b, _ = strconv.Atoi(scanner.Text())
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
	}
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = -1
	}
	d[u-1] = 0
	dfs(u-1, d, edges)
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = -1
	}
	e[v-1] = 0
	dfs(v-1, e, edges)
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}
	if q <= 0 {
		fmt.Println(0)
	} else {
		fmt.Println(q - 1)
	}
}

func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == -1 {
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}

