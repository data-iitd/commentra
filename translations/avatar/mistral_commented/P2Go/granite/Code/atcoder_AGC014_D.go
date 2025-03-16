
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	N := readNum(reader)
	adj := make([][]int, N+1)
	for i := 0; i < N+1; i++ {
		adj[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
	que := make([]int, 0, N)
	var p []int
	var v []int
	var c []int

	seen := make([]bool, N+1)
	par := make([]int, N+1)
	child_num := make([]int, N+1)

	que = append(que, 1)
	seen[1] = true

	for len(que) > 0 {
		u := que[0]
		que = que[1:]
		p = append(p, u)
		for _, v = range adj[u] {
			if!seen[v] {
				seen[v] = true
				par[v] = u
				child_num[u]++
				que = append(que, v)
			}
		}
	}

	seq := make([]int, 0, N)

	for i := 0; i < len(p); i++ {
		u := p[i]
		if child_num[u] == 0 {
			seq = append(seq, u)
		}
	}

	for len(seq) > 0 {
		u := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		if seen[par[u]] {
			continue
		}
		seen[par[u]] = true
		child_num[par[par[u]]]--
		if child_num[par[par[u]]] == 0 {
			seq = append(seq, par[par[u]])
		}
	}

	for i := 1; i <= N; i++ {
		if!seen[i] {
			fmt.Println("First")
			return
		}
	}

	fmt.Println("Second")
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	N := readNum(reader)
	adj := make([][]int, N+1)
	for i := 0; i < N+1; i++ {
		adj[i] = make([]int, 0, 2)
	}
	for i := 0; i < N-1; i++ {
		a, b := readTwoNums(reader)
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
	que := make([]int, 0, N)
	var p []int
	var v []int
	var c []int

	seen := make([]bool, N+1)
	par := make([]int, N+1)
	child_num := make([]int, N+1)

	que = append(que, 1)
	seen[1] = true

	for len(que) > 0 {
		u := que[0]
		que = que[1:]
		p = append(p, u)
		for _, v = range adj[u] {
			if!seen[v] {
				seen[v] = true
				par[v] = u
				child_num[u]++
				que = append(que, v)
			}
		}
	}

	seq := make([]int, 0, N)

	for i := 0; i < len(p); i++ {
		u := p[i]
		if child_num[u] == 0 {
			seq = append(seq, u)
		}
	}

	for len(seq) > 0 {
		u := seq[len(seq)-1]
		seq = seq[:len(seq)-1]
		if seen[par[u]] {
			continue
		}
		seen[par[u]] = true
		child_num[par[par[u]]]--
		if child_num[par[par[u]]] == 0 {
			seq = append(seq, par[par[u]])
		}
	}

	for i := 1; i <= N; i++ {
		if!seen[i] {
			fmt.Println("First")
			return
		}
	}

	fmt.Println("Second")
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}