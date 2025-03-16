package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)

	adj := make([][]int, N+1)
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}

	que := []int{1}
	seen := make([]int, N+1)
	seen[1] = 1
	par := make([]int, N+1)
	childNum := make([]int, N+1)

	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		for _, u := range adj[v] {
			if seen[u] == 0 {
				seen[u] = 1
				par[u] = v
				childNum[v]++
				que = append(que, u)
			}
		}
	}

	seq := []int{}
	for i := 1; i <= N; i++ {
		if childNum[i] == 0 {
			seq = append(seq, i)
		}
	}

	for len(seq) > 0 {
		c := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		seen[c] = 0
		if seen[par[c]] == 0 {
			fmt.Fprintln(writer, "First")
			return
		}
		seen[par[c]] = 0
		childNum[par[par[c]]]--
		if childNum[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}
	fmt.Fprintln(writer, "Second")
}

// <END-OF-CODE>
