package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	adj := make([][]int, n+1)
	for i := 0; i < n-1; i++ {
		a, b := readNums(reader)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
	que := make([]int, 0)
	que = append(que, 1)
	seen := make([]int, n+1)
	seen[1] = 1
	par := make([]int, n+1)
	child_num := make([]int, n+1)
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		for _, u := range adj[v] {
			if seen[u] == 0 {
				seen[u] = 1
				par[u] = v
				child_num[v] += 1
				que = append(que, u)
			}
		}
	}
	seq := make([]int, 0)
	for i := 1; i <= n; i++ {
		if child_num[i] == 0 {
			seq = append(seq, i)
		}
	}
	for len(seq) > 0 {
		c := seq[0]
		seen[c] = 0
		if seen[par[c]] == 0 {
			fmt.Println("First")
			return
		}
		seen[par[c]] = 0
		child_num[par[par[c]]] -= 1
		if child_num[par[par[c]]] == 0 {
			seq = append(seq, par[par[c]])
		}
	}
	fmt.Println("Second")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return string(str)
}

func readNums(reader *bufio.Reader) (int, int) {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return 0, 0
	}

	str = strings.Split(string(str), " ")
	a, _ := strconv.Atoi(str[0])
	b, _ := strconv.Atoi(str[1])

	return a, b
}

