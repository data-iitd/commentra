
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, ta, ao := readThreeNums(reader)
		ta--
		ao--
		g := make([][]int, n)
		for i := 0; i < n-1; i++ {
			a, b := readTwoNums(reader)
			a--
			b--
			g[a] = append(g[a], b)
			g[b] = append(g[b], a)
		}
		res := solve(n, ta, ao, g)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
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

func solve(n int, ta int, ao int, g [][]int) int {
	dist := make([]int, n)
	var dfs func(p int, u int)

	dfs = func(p int, u int) {
		for _, v := range g[u] {
			if v == p {
				continue
			}
			dist[v] = dist[u] + 1
			dfs(u, v)
		}
	}

	dist[ta] = 0
	dfs(-1, ta)

	res := dist[ao]

	dfs = func(p int, u int) {
		for _, v := range g[u] {
			if v == p {
				continue
			}
			if dist[v] < dist[u] {
				continue
			}
			res = max(res, dist[v])
			dfs(u, v)
		}
	}

	dfs(-1, ao)

	return res
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func solve1(n int, ta int, ao int, g [][]int) int {
	dist := make([]int, n)
	var dfs func(p int, u int)

	dfs = func(p int, u int) {
		for _, v := range g[u] {
			if v == p {
				continue
			}
			dist[v] = dist[u] + 1
			dfs(u, v)
		}
	}

	dist[ta] = 0
	dfs(-1, ta)

	res := dist[ao]

	dfs = func(p int, u int) {
		for _, v := range g[u] {
			if v == p {
				continue
			}
			if dist[v] < dist[u] {
				continue
			}
			res = max(res, dist[v])
			dfs(u, v)
		}
	}

	dfs(-1, ao)

	return res
}