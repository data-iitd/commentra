package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(readLine(reader))
	adj := make([][]int, N+1)
	for i := 0; i < N-1; i++ {
		line := readLine(reader)
		ab := splitInts(line, " ")
		a, b := ab[0], ab[1]
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
	que := []int{1}
	seen := make([]int, N+1)
	seen[1] = 1
	par := make([]int, N+1)
	child_num := make([]int, N+1)
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		for _, u := range adj[v] {
			if seen[u] == 0 {
				seen[u] = 1
				par[u] = v
				child_num[v]++
				que = append(que, u)
			}
		}
	}
	seq := []int{}
	for i := 1; i <= N; i++ {
		if child_num[i] == 0 {
			seq = append(seq, i)
		}
	}
	for len(seq) > 0 {
		c := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		seen[c] = 0
		if seen[par[c]] == 0 {
			fmt.Println("First")
			return
		}
		seen[par[c]] = 0
		child_num[par[par[c]]]--
		if child_num[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}
	fmt.Println("Second")
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

func splitInts(line, sep string) []int {
	strs := strings.Split(line, sep)
	ints := make([]int, len(strs))
	for i, str := range strs {
		ints[i], _ = strconv.Atoi(str)
	}
	return ints
}
