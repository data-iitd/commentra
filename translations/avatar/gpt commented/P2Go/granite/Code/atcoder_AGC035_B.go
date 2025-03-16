
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)

	edges := make([][]int, n)
	for i := 0; i < n; i++ {
		edges[i] = make([]int, 0)
	}
	degs := make([]int, n)
	parity := make([]int, n)
	visited := make([]bool, n)

	for i := 0; i < m; i++ {
		var a, b int
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		a--
		b--
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
		degs[a]++
		degs[b]++
	}

	if m%2!= 0 {
		fmt.Println(-1)
		return
	}

	type degree struct {
		deg int
		idx int
	}
	var q []degree
	for i := 0; i < n; i++ {
		q = append(q, degree{deg: degs[i], idx: i})
	}
	sort.Slice(q, func(i, j int) bool {
		return q[i].deg < q[j].deg
	})

	for len(q) > 0 {
		d := q[0]
		q = q[1:]

		if visited[d.idx] {
			continue
		}
		visited[d.idx] = true

		for _, v := range edges[d.idx] {
			edges[v] = remove(edges[v], d.idx)
			if parity[d.idx]!= 0 && edges[v][0] == d.idx {
				fmt.Printf("%d %d\n", d.idx+1, v+1)
				parity[d.idx] = 1 - parity[d.idx]
			} else {
				fmt.Printf("%d %d\n", v+1, d.idx+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			q = append(q, degree{deg: degs[v], idx: v})
		}
	}
}

func remove(s []int, x int) []int {
	for i, v := range s {
		if v == x {
			return append(s[:i], s[i+1:]...)
		}
	}
	return s
}

