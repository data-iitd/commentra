
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
		H := readNNums(reader, n)
		E := make([][]int, m)
		for i := 0; i < m; i++ {
			E[i] = readNNums(reader, 2)
		}
		res := solve(n, m, H, E)
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

func solve(n int, m int, H []int, E [][]int) int {
	g := NewGraph(n, 2*m)

	for _, e := range E {
		u, v := e[0]-1, e[1]-1
		g.AddEdge(u, v)
		g.AddEdge(v, u)
	}

	var res int

	for u := 0; u < n; u++ {
		ok := true
		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if H[u] <= H[v] {
				ok = false
				break
			}
		}
		if ok {
			res++
		}
	}

	return res
}

type Graph struct {
	nodes []int
	next  []int
	to    []int
	cur   int
}

func NewGraph(n int, e int) *Graph {
	nodes := make([]int, n)
	next := make([]int, e+1)
	to := make([]int, e+1)
	return &Graph{nodes, next, to, 0}
}

func (g *Graph) AddEdge(u, v int) {
	g.cur++
	g.next[g.cur] = g.nodes[u]
	g.nodes[u] = g.cur
	g.to[g.cur] = v
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		H := readNNums(reader, n)
		E := make([][]int, m)
		for i := 0; i < m; i++ {
			E[i] = readNNums(reader, 2)
		}
		res := solve(n, m, H, E)
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

func solve(n int, m int, H []int, E [][]int) int {
	g := NewGraph(n, 2*m)

	for _, e := range E {
		u, v := e[0]-1, e[1]-1
		g.AddEdge(u, v)
		g.AddEdge(v, u)
	}

	var res int

	for u := 0; u < n; u++ {
		ok := true
		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if H[u] <= H[v] {
				ok = false
				break
			}
		}
		if ok {
			res++
		}
	}

	return res
}

type Graph struct {
	nodes []int
	next  []int
	to    []int
	cur   int
}

func NewGraph(n int, e int) *Graph {
	nodes := make([]int, n)
	next := make([]int, e+1)
	to := make([]int, e+1)
	return &Graph{nodes, next, to, 0}
}

func (g *Graph) AddEdge(u, v int) {
	g.cur++
	g.next[g.cur] = g.nodes[u]
	g.nodes[u] = g.cur
	g.to[g.cur] = v
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, m := readTwoNums(reader)
		H := readNNums(reader, n)
		E := make([][]int, m)
		for i := 0; i < m; i++) {
			E[i] = readNNums(reader, 2)
		}
		res := solve(n, m, H, E)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}
	fmt.Print(buf.String())
}

int main() {
	cin >> N >> M;
	rep(i, N) {
		cin >> H[i];
	}
	rep(i, M) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = 0;
	rep(i, N) {
		if (H[i] <= H[j]) {
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {
	cin >> N >> M;
	rep(i, N) {
		cin >> H[i];
	}
	rep(i, M) {
		rep(i, 2) {
			E[i] = readNNums(cin, 2);
		}
		rep(i, N) {
		rep(i, M) {
			ans++;
		}
	}
	rep(i, N) {
		rep(i, M) {
			ans++;
		}
	}
	rep(i, N) {
		rep(i, M) {
			ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	rep(i, M) {
		ans++;
		}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	}
	rep(i, M) {
		ans++;
		}
	}
	}
	}
	rep(i, N) {
		ans++;
		}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	