
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		G := make([][]int, n)
		for i := 0; i < n; i++ {
			G[i] = make([]int, 0, 2)
		}
		E := make(map[int]int)
		for i := 0; i < n-1; i++ {
			a, b := readTwoNums(reader)
			a--
			b--
			G[a] = append(G[a], b)
			G[b] = append(G[b], a)
			E[a*n+b] = 0
		}
		res := solve(n, G, E)
		var buf bytes.Buffer
		buf.WriteString(fmt.Sprintf("%d\n", res))
		for u := 0; u < n; u++ {
			for _, v := range G[u] {
				if u > v {
					continue
				}
				buf.WriteString(fmt.Sprintf("%d\n", E[u*n+v]))
			}
		}
		fmt.Print(buf.String())
	}
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

func solve(n int, G [][]int, E map[int]int) int {
	vis := make([]bool, n)
	var dfs func(p, u int) int

	dfs = func(p, u int) int {
		vis[u] = true
		var res int
		for _, v := range G[u] {
			if!vis[v] {
				res = max(res, dfs(u, v))
			}
		}
		res++
		for _, v := range G[u] {
			if v > p {
				E[u*n+v] = res
				E[v*n+u] = res
			}
		}
		return res
	}

	dfs(-1, 0)

	var res int

	for _, v := range G[0] {
		res = max(res, E[0*n+v])
	}

	return res
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

