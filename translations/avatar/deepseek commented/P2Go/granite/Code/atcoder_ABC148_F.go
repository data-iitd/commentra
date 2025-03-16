
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of nodes, starting node for Ta, and starting node for Ao
	n, ta, ao := readThreeNums(reader)

	// Adjust indices to be zero-based
	ta--
	ao--

	// Initialize the graph as a list of lists, each representing adjacency list of a node
	g := make([][]int, n)

	// Read edges to construct the graph
	for i := 0; i < n-1; i++ {
		a, b := readTwoNums(reader)
		a--
		b--
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	// Initialize distance arrays to None, will be populated during DFS
	taDist := make([]int, n)
	taDist[ta] = 0 // Distance from Ta to Ta is 0
	aoDist := make([]int, n)
	aoDist[ao] = 0 // Distance from Ao to Ao is 0

	// Depth-First Search (DFS) function to compute distances from Ta
	var dfs1 func(p, u int)
	dfs1 = func(p, u int) {
		for _, v := range g[u] {
			if taDist[v]!= -1 { // If already visited, skip
				continue
			}
			taDist[v] = taDist[p] + 1 // Update distance
			dfs1(u, v) // Recursively visit neighbors
		}
	}

	// Depth-First Search (DFS) function to compute distances from Ao
	var dfs2 func(p, u int)
	dfs2 = func(p, u int) {
		for _, v := range g[u] {
			if aoDist[v]!= -1 { // If already visited, skip
				continue
			}
			aoDist[v] = aoDist[p] + 1 // Update distance
			dfs2(u, v) // Recursively visit neighbors
		}
	}

	// Start DFS from Ao to compute distances
	dfs2(ao, ao)

	// Start DFS from Ta to compute distances
	dfs1(ta, ta)

	// Initialize result variable
	res := 0

	// Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
	for i := 0; i < n; i++ {
		if taDist[i] > aoDist[i] { // Skip if Ta's distance is greater
			continue
		}
		res = max(res, aoDist[i]) // Update result with the maximum distance
	}

	// Print the result, which is the maximum distance minus one
	fmt.Println(res - 1)
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

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int) int {
	return a + b - max(a, b)
}

func maxInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func max64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func pow(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a
	}
	return res
}

func pow3(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a * a * a
	}
	return res
}

func pow64(a, b int) int64 {
	res := int64(1)
	for i := 0; i < b; i++ {
		res *= int64(a)
	}
	return res
}

func pow364(a, b int) int64 {
	res := int64(1)
	for i := 0; i < b; i++ {
		res *= int64(a * a * a)
	}
	return res
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}

func abs64(num int64) int64 {
	if num < 0 {
		return -num
	}
	return num
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func max5(a, b, c, d, e int) int {
	return max(max(a, b), max(c, d), e)
}

func min5(a, b, c, d, e int) int {
	return min(min(a, b), min(c, d), e)
}

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func check(n int) bool {
	for n > 1 {
		if n%10 == 0 || n%10 == 1 {
			n /= 10
		} else {
			return false
		}
	}
	return true
}

func reverse(x int) int {
	var res int
	for x > 0 {
		res = res*10 + x%10
		x /= 10
	}
	return res
}

func reverse64(x int64) int64 {
	var res int64
	for x > 0 {
		res = res*10 + x%10
		x /= 10
	}
	return res
}

func reverseStr(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
	res := make([]uint64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readUint64(s, pos, &res[i]) + 1
	}

	return res
}

func main1() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(n, A)
		fmt.Println(res)
	}
}

func solve(n int, A []int) int {
	// Your solution code here
}

func solve1(n int, A []int) int {
	// Your solution code here
}

func solve2(n int, A []int) int {
	// Your solution code here
}

func solve3(n int, A []int) int {
	// Your solution code here
}

func solve4(n int, A []int) int {
	// Your solution code here
}

func solve5(n int, A []int) int {
	// Your solution code here
}

func solve6(n int, A []int) int {
	// Your solution code here
}

func solve7(n int, A []int) int {
	// Your solution code here
}

func solve8(n int, A []int) int {
	// Your solution code here
}

func solve9(n int, A []int) int {
	// Your solution code here
}

func solve10(n int, A []int) int {
	// Your solution code here
}

func solve11(n int, A []int) int {
	// Your solution code here
}

func solve12(n int, A []int) int {
	// Your solution code here
}

func solve13(n int, A []int) int {
	// Your solution code here
}

func solve14(n int, A []int) int {
	// Your solution code here
}

func solve15(n int, A []int) int {
	// Your solution code here
}

func solve16(n int, A []int) int {
	// Your solution code here
}

func solve17(n int, A []int) int {
	// Your solution code here
}

func solve18(n int, A []int) int {
	// Your solution code here
}

func solve19(n int, A []int) int {
	// Your solution code here
}

func solve20(n int, A []int) int {
	// Your solution code here
}

func solve21(n int, A []int) int {
	// Your solution code here
}

func solve22(n int, A []int) int {
	// Your solution code here
}

func solve23(n int, A []int) int {
	// Your solution code here
}

func solve24(n int, A []int) int {
	// Your solution code here
}

func solve25(n int, A []int) int {
	// Your solution code here
}

func solve26(n int, A []int) int {
	// Your solution code here
}

func solve27(n int, A []int) int {
	// Your solution code here
}

func solve28(n int, A []int) int {
	// Your solution code here
}

func solve29(n int, A []int) int {
	// Your solution code here
}

func solve30(n int, A []int) int {
	// Your solution code here
}

func solve31(n int, A []int) int {
	// Your solution code here
}

func solve32(n int, A []int) int {
	// Your solution code here
}

func solve33(n int, A []int) int {
	// Your solution code here
}

func solve34(n int, A []int) int {
	// Your solution code here
}

func solve35(n int, A []int) int {
	// Your solution code here
}

func solve36(n int, A []int) int {
	// Your solution code here
}

func solve37(n int, A []int) int {
	// Your solution code here
}

func solve38(n int, A []int) int {
	// Your solution code here
}

func solve39(n int, A []int) int {
	// Your solution code here
}

func solve40(n int, A []int) int {
	// Your solution code here
}

func solve41(n int, A []int) int {
	// Your solution code here
}

func solve42(n int, A []int) int {
	// Your solution code here
}

func solve43(n int, A []int) int {
	// Your solution code here
}

func solve44(n int, A []int) int {
	// Your solution code here
}

func solve45(n int, A []int) int {
	// Your solution code here
}

func solve46(n int, A []int) int {
	// Your solution code here
}

func solve47(n int, A []int) int {
	// Your solution code here
}

func solve48(n int, A []int) int {
	// Your solution code here
}

func solve49(n int, A []int) int {
	// Your solution code here
}

func solve50(n int, A []int) int {
	// Your solution code here
}

func solve51(n int, A []int) int {
	// Your solution code here
}

func solve52(n int, A []int) int {
	// Your solution code here
}

func solve53(n int, A []int) int {
	// Your solution code here
}

func solve54(n int, A []int) int {
	// Your solution code here
}

func solve55(n int, A []int) int {
	// Your solution code here
}

func solve56(n int, A []int) int {
	// Your solution code here
}

func solve57(n int, A []int) int {
	// Your solution code here
}

func solve58(n int, A []int) int {
	// Your solution code here
}

func solve59(n int, A []int) int {
	// Your solution code here
}

func solve60(n int, A []int) int {
	// Your solution code here
}

func solve61(n int, A []int) int {
	// Your solution code here
}

func solve62(n int, A []int) int {
	// Your solution code here
}

func solve63(n int, A []int) int {
	// Your solution code here
}

func solve64(n int, A []int) int {
	// Your solution code here
}

func solve65(n int, A []int) int {
	// Your solution code here
}

func solve66(n int, A []int) int {
	// Your solution code here
}

func solve67(n int, A []int) i