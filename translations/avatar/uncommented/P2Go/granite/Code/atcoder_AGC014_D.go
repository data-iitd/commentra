
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	readWriter = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	inputReader = bufio.NewReader(os.Stdin)
)

func main() {
	var N int
	fmt.Fscanf(inputReader, "%d\n", &N)
	adj := make([][]int, N+1)
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Fscanf(inputReader, "%d %d\n", &a, &b)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
	que := make([]int, 0)
	que = append(que, 1)
	seen := make([]bool, N+1)
	seen[1] = true
	par := make([]int, N+1)
	childNum := make([]int, N+1)
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
	seq := make([]int, 0)
	for i := 1; i <= N; i++ {
		if childNum[i] == 0 {
			seq = append(seq, i)
		}
	}
	for len(seq) > 0 {
		c := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		seen[c] = false
		if!seen[par[c]] {
			fmt.Fprint(readWriter, "First\n")
			readWriter.Flush()
			os.Exit(0)
		}
		seen[par[par[c]]] = false
		childNum[par[par[c]]]--
		if childNum[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}
	fmt.Fprint(readWriter, "Second\n")
	readWriter.Flush()
}
