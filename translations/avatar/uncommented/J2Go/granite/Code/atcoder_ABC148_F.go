
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	N := nextInt(sc)
	u := nextInt(sc) - 1
	v := nextInt(sc) - 1
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}
	for i := 0; i < N-1; i++ {
		a := nextInt(sc) - 1
		b := nextInt(sc) - 1
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = 1 << 30
	}
	d[u] = 0
	dfs(u, d, edges)
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = 1 << 30
	}
	e[v] = 0
	dfs(v, e, edges)
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}
	fmt.Println(q)
}

func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == 1<<30 {
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}