
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func dfs(links [][]int, n, k, v, p int) (int, int) {
	heightFromLeaf := 0
	cutCount := 0

	for _, u := range links[v] {
		if u == 0 {
			continue
		}

		hgt, cut := dfs(links, n, k, u, v)

		heightFromLeaf = max(heightFromLeaf, hgt)
		cutCount += cut
	}

	heightFromLeaf += 1

	if p!= 0 && heightFromLeaf == k {
		heightFromLeaf = 0
		cutCount += 1
	}

	return heightFromLeaf, cutCount
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	n, k := nextInt(sc), nextInt(sc)
	aaa := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		aaa[i] = nextInt(sc)
	}

	links := make([][]int, n)
	for i := 0; i < n; i++ {
		links[i] = make([]int, 0)
	}

	for i, a := range aaa {
		a--
		links[a] = append(links[a], i+1)
	}

	_, ans := dfs(links, n, k, 0, 0)

	if aaa[0]!= 1 {
		ans += 1
	}

	fmt.Println(ans)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
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

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := solve(n, k, A)
		fmt.Println(res)
	}
}

func solve(n, k int, A []int) int {
	g := NewGraph(n, len(A))

	for i, u := range A {
		v := i + 2
		g.AddEdge(u, v)
	}

	var dfs func(p, u int) (int, int)

	dfs = func(p, u int) (int, int) {
		var height, cut int

		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if p == v {
				continue
			}

			h, c := dfs(u, v)

			height = max(height, h)
			cut += c
		}

		height++

		if p > 0 && height == k {
			height = 0
			cut++
		}

		return height, cut
	}

	_, res := dfs(0, 1)

	if A[0]!= 1 {
		res++
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

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := solve(n, k, A)
		fmt.Println(res)
	}
}

func solve(n, k int, A []int) int {
	g := NewGraph(n, len(A))

	for i, u := range A {
		v := i + 2
		g.AddEdge(u, v)
	}

	var dfs func(p, u int) (int, int)

	dfs = func(p, u int) (int, int) {
		var height, cut int

		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if p == v {
				continue
			}

			h, c := dfs(u, v)

			height = max(height, h)
			cut += c
		}

		height++

		if p > 0 && height == k {
			height = 0
			cut++
		}

		return height, cut
	}

	_, res := dfs(0, 1)

	if A[0]!= 1 {
		res++
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

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := solve(n, k, A)
		fmt.Println(res)
	}
}

func solve(n, k int, A []int) int {
	g := NewGraph(n, len(A))

	for i, u := range A {
		v := i + 2
		g.AddEdge(u, v)
	}

	var dfs func(p, u int) (int, int)

	dfs = func(p, u int) (int, int) {
		var height, cut int

		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if p == v {
				continue
			}

			h, c := dfs(u, v)

			height = max(height, h)
			cut += c
		}

		height++

		if p > 0 && height == k {
			height = 0
			cut++
		}

		return height, cut
	}

	_, res := dfs(0, 1)

	if A[0]!= 1 {
		res++
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

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := solve(n, k, A)
		fmt.Println(res)
	}
}

func solve(n, k int, A []int) int {
	g := NewGraph(n, len(A))

	for i, u := range A {
		v := i + 2
		g.AddEdge(u, v)
	}

	var dfs func(p, u int) (int, int)

	dfs = func(p, u int) (int, int) {
		var height, cut int

		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if p == v {
				continue
			}

			h, c := dfs(u, v)

			height = max(height, h)
			cut += c
		}

		height++

		if p > 0 && height == k {
			height = 0
			cut++
		}

		return height, cut
	}

	_, res := dfs(0, 1)

	if A[0]!= 1 {
		res++
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

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := solve(n, k, A)
		fmt.Println(res)
	}
}

func solve(n, k int, A []int) int {
	g := NewGraph(n, len(A))

	for i, u := range A {
		v := i + 2
		g.AddEdge(u, v)
	}

	var dfs func(p, u int) (int, int)

	dfs = func(p, u int) (int, int) {
		var height, cut int

		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if p == v {
				continue
			}

			h, c := dfs(u, v)

			height = max(height, h)
			cut += c
		}

		height++

		if p > 0 && height == k {
			height = 0
			cut++
		}

		return height, cut
	}

	_, res := dfs(0, 1)

	if A[0]!= 1 {
		res++
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

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := solve(n, k, A)
		fmt.Println(res)
	}
}

func solve(n, k int, A []int) int {
	g := NewGraph(n, len(A))

	for i, u := range A {
		v := i + 2
		g.AddEdge(u, v)
	}

	var dfs func(p, u int) (int, int)

	dfs = func(p, u int) (int, int) {
		var height, cut int

		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if p == v {
				continue
			}

			h, c := dfs(u, v)

			height = max(height, h)
			cut += c
		}

		height++

		if p > 0 && height == k {
			height = 0
			cut++
		}

		return height, cut
	}

	_, res := dfs(0, 1)

	if A[0]!= 1 {
		res++
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

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := solve(n, k, A)
		fmt.Println(res)
	}
}

func solve(n, k int, A []int) int {
	g := NewGraph(n, len(A))

	for i, u := range A {
		v := i + 2
		g.AddEdge(u, v)
	}

	var dfs func(p, u int) (int, int)

	dfs = func(p, u int) (int, int) {
		var height, cut int
		for i := g.nodes[u]; i > 0; i = g.next[i] {
			v := g.to[i]
			if p == v {
				continue
			}

			h, c := dfs(u, v)

			height = max(height, h)
			cut += c
		}

		height++

		if p > 0 && height == k {
			height = 0
			cut++
		}

		return height, cut
	}

	return height, cut
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n-1)
		res := 