
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	adj := make([][]int, n+1)
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}

	seen := make([]bool, n+1)
	par := make([]int, n+1)
	childNum := make([]int, n+1)

	que := []int{1}
	seen[1] = true
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		for _, u := range adj[v] {
			if!seen[u] {
				seen[u] = true
				par[u] = v
				childNum[v]++
				que = append(que, u)
			}
		}
	}

	seq := []int{}
	for i := 1; i <= n; i++ {
		if childNum[i] == 0 {
			seq = append(seq, i)
		}
	}

	for len(seq) > 0 {
		c := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		seen[c] = false
		if!seen[par[c]] {
			fmt.Println("First")
			return
		}
		seen[par[c]] = false
		childNum[par[par[c]]]--
		if childNum[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}

	fmt.Println("Second")
}
