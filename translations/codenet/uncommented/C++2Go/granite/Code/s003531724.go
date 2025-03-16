
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
		n, m := readTwoNums(reader)
		E := make([][]int, n)
		for i := 0; i < n; i++ {
			E[i] = make([]int, 0, 2)
		}
		for i := 0; i < m; i++ {
			u, v := readTwoNums(reader)
			u--
			v--
			E[u] = append(E[u], v)
			E[v] = append(E[v], u)
		}
		res := solve(n, E)
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

func solve(n int, E [][]int) int64 {
	vis := make([]bool, n)
	var dfs func(p int, cur int)

	dfs = func(p int, cur int) {
		vis[p] = true
		cnt[cur]++
		d[p] = cur
		for _, to := range E[p] {
			if!vis[to] {
				dfs(to, (cur+1)%3)
			} else if d[to]!= (cur+1)%3 {
				ok = false
			}
		}
	}

	var res int64

	for p := 0; p < n; p++ {
		if!vis[p] {
			T = 0
			for i := 0; i < 3; i++ {
				cnt[i] = 0
			}
			ok = true
			dfs(p, 0)
			s := cnt[0] + cnt[1] + cnt[2]
			if!ok {
				res += int64(s) * int64(s)
			} else {
				if cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 {
					res += int64(cnt[0]) * int64(cnt[1]) + int64(cnt[1]) * int64(cnt[2]) + int64(cnt[2]) * int64(cnt[0])
				} else {
					res += int64(T) / 2
				}
			}
		}
	}

	return res
}

var cnt [3]int
var d [100001]int
var ok bool
var T int

