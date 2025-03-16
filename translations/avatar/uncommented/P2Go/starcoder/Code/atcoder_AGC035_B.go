package main
import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N, M int
	fmt.Scanf("%d %d", &N, &M)
	edges := make([][]int, N)
	degs := make([]int, N)
	parity := make([]int, N)
	flag := make([]bool, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0)
	}
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Scanf("%d %d", &a, &b)
		edges[a-1] = append(edges[a-1], b-1)
		edges[b-1] = append(edges[b-1], a-1)
		degs[a-1]++
		degs[b-1]++
	}
	if M%2!= 0 {
		fmt.Println(-1)
		return
	}
	Q := make([]int, 0)
	for i, d := range degs {
		Q = append(Q, d)
		Q = append(Q, i)
	}
	sort.Ints(Q)
	for len(Q) > 0 {
		d := Q[0]
		u := Q[1]
		Q = Q[2:]
		if flag[u] {
			continue
		}
		flag[u] = true
		for i, v := range edges[u] {
			edges[v] = append(edges[v], u)
			if parity[u]!= 0 && i == 0 {
				fmt.Printf("%d %d\n", u+1, v+1)
				parity[u] = 1 - parity[u]
			} else {
				fmt.Printf("%d %d\n", v+1, u+1)
				parity[v] = 1 - parity[v]
			}
			degs[v]--
			Q = append(Q, degs[v])
			Q = append(Q, v)
		}
	}
}

