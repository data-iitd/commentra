
// Include necessary packages for input/output, data manipulation, and other functionalities
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Define constants and data structures
const (
	MAX_L = 22
	MOD    = 1000000007
	INF    = 1145141919
)

var (
	N int
	G [][2]int64
	U [MAX_L][100000]int
	R [100000]int
	L [100000]int64
)

// Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
func dfs(x, p, r int, l int64) {
	U[0][x] = p
	R[x] = r
	L[x] = l
	for _, pp := range G[x] {
		t := pp[0]
		if t == p {
			continue
		}
		dfs(int(t), x, r+1, l+pp[1])
	}
}

// Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
func lca(a, b int) int {
	if R[a] > R[b] {
		a, b = b, a
	}
	for i := 0; i < MAX_L; i++ {
		if (R[a]-R[b])>>i&1 == 1 {
			b = U[i][b]
		}
	}
	if a == b {
		return a
	}
	for i := MAX_L - 1; i >= 0; i-- {
		if U[i][a]!= U[i][b] {
			a = U[i][a]
			b = U[i][b]
		}
	}
	return U[0][a]
}

// Distance calculation function to find the distance between two nodes
func dist(x, y int) int64 {
	g := lca(x, y)
	return L[x] + L[y] - 2*L[g]
}

// Main function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var buf bytes.Buffer
	scanner.Scan()
	N = nextInt(scanner.Text())
	G = make([][2]int64, N)
	for i := 0; i < MAX_L; i++ {
		for j := 0; j < N; j++ {
			U[i][j] = -1
		}
	}
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		x := nextInt(scanner.Text())
		scanner.Scan()
		y := nextInt(scanner.Text())
		scanner.Scan()
		c := nextInt64(scanner.Text())
		x--
		y--
		G[x] = append(G[x], [2]int64{int64(y), c})
		G[y] = append(G[y], [2]int64{int64(x), c})
	}
	dfs(0, -1, 0, 0)
	for i := 0; i < MAX_L-1; i++ {
		for v := 0; v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1
			}
			U[i+1][v] = U[i][U[i][v]]
		}
	}
	var Q, K int
	scanner.Scan()
	Q = nextInt(scanner.Text())
	scanner.Scan()
	K = nextInt(scanner.Text())
	K--
	for i := 0; i < Q; i++ {
		scanner.Scan()
		x := nextInt(scanner.Text())
		scanner.Scan()
		y := nextInt(scanner.Text())
		x--
		y--
		buf.WriteString(fmt.Sprintf("%d\n", dist(x, K)+dist(K, y)))
	}
	fmt.Print(buf.String())
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextNumber(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, err := strconv.ParseFloat(sc.Text(), 32)
	if err!= nil {
		panic(err)
	}
	return f
}

func nextInt(s string) int {
	i, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return i
}

func nextInt64(s string) int64 {
	i, err := strconv.ParseInt(s, 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func minInt64(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func maxInt64(x, y int64) int64 {
	if x < y {
		return y
	}
	return x
}

func abs(x int) int {
	return x * (-1)
}

func pow(x, n int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func powMod(x, n, mod int) int {
	ret := 1
	for i := 0; i < n; i++ {
		ret = (ret * x) % mod
	}
	return ret
}

func formatInt(num int) string {
	return strconv.Itoa(num)
}

func formatInt64(num int64) string {
	return strconv.FormatInt(num, 10)
}

func formatFloat(num float64, digit int) string {
	return strconv.FormatFloat(num, 'f', digit, 64)
}

func formatUInt64(num uint64) string {
	return strconv.FormatUint(num, 10)
}

func formatUInt(num uint) string {
	return strconv.FormatUint(uint64(num), 10)
}

func formatBool(b bool) string {
	if b {
		return "Yes"
	}
	return "No"
}

func formatString(str string) string {
	return str
}

func formatArray(arr []int) string {
	ret := ""
	for i := 0; i < len(arr); i++ {
		ret += formatInt(arr[i])
		if i!= len(arr)-1 {
			ret += " "
		}
	}
	return ret
}

func formatArrayString(arr []string) string {
	ret := ""
	for i := 0; i < len(arr); i++ {
		ret += formatString(arr[i])
		if i!= len(arr)-1 {
			ret += " "
		}
	}
	return ret
}

func formatArrayInt64(arr []int64) string {
	ret := ""
	for i := 0; i < len(arr); i++ {
		ret += formatInt64(arr[i])
		if i!= len(arr)-1 {
			ret += " "
		}
	}
	return ret
}

func formatArrayUInt64(arr []uint64) string {
	ret := ""
	for i := 0; i < len(arr); i++ {
		ret += formatUInt64(arr[i])
		if i!= len(arr)-1 {
			ret += " "
		}
	}
	return ret
}

func formatArrayUInt(arr []uint) string {
	ret := ""
	for i := 0; i < len(arr); i++ {
		ret += formatUInt(arr[i])
		if i!= len(arr)-1 {
			ret += " "
		}
	}
	return ret
}

func formatArrayBool(arr []bool) string {
	ret := ""
	for i := 0; i < len(arr); i++ {
		ret += formatBool(arr[i])
		if i!= len(arr)-1 {
			ret += " "
		}
	}
	return ret
}

func formatArrayFloat(arr []float64, digit int) string {
	ret := ""
	for i := 0; i < len(arr); i++ {
		ret += formatFloat(arr[i], digit)
		if i!= len(arr)-1 {
			ret += " "
		}
	}
	return ret
}

func formatMapInt(mp map[int]int) string {
	ret := ""
	for k, v := range mp {
		ret += formatInt(k) + ":" + formatInt(v) + " "
	}
	return ret
}

func formatMapInt64(mp map[int]int64) string {
	ret := ""
	for k, v := range mp {
		ret += formatInt(k) + ":" + formatInt64(v) + " "
	}
	return ret
}

func formatMapIntString(mp map[int]string) string {
	ret := ""
	for k, v := range mp {
		ret += formatInt(k) + ":" + formatString(v) + " "
	}
	return ret
}

func formatMapStringInt(mp map[string]int) string {
	ret := ""
	for k, v := range mp {
		ret += formatString(k) + ":" + formatInt(v) + " "
	}
	return ret
}

func formatMapStringInt64(mp map[string]int64) string {
	ret := ""
	for k, v := range mp {
		ret += formatString(k) + ":" + formatInt64(v) + " "
	}
	return ret
}

func formatMapStringBool(mp map[string]bool) string {
	ret := ""
	for k, v := range mp {
		ret += formatString(k) + ":" + formatBool(v) + " "
	}
	return ret
}

func formatMapStringString(mp map[string]string) string {
	ret := ""
	for k, v := range mp {
		ret += formatString(k) + ":" + formatString(v) + " "
	}
	return ret
}

func formatMapInt64Int64(mp map[int64]int64) string {
	ret := ""
	for k, v := range mp {
		ret += formatInt64(k) + ":" + formatInt64(v) + " "
	}
	return ret
}

func formatMapInt64String(mp map[int64]string) string {
	ret := ""
	for k, v := range mp {
		ret += formatInt64(k) + ":" + formatString(v) + " "
	}
	return ret
}

func formatMapInt64Bool(mp map[int64]bool) string {
	ret := ""
	for k, v := range mp {
		ret += formatInt64(k) + ":" + formatBool(v) + " "
	}
	return ret
}

func formatMapInt64Int(mp map[int64]int) string {
	ret := ""
	for k, v := range mp {
		ret += formatInt64(k) + ":" + formatInt(v) + " "
	}
	return ret
}

func formatMapInt64Int64String(mp map[int64]map[int64]string) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":"
		for k2, v2 := range v1 {
			ret += formatInt64(k2) + ":" + formatString(v2) + " "
		}
	}
	return ret
}

func formatMapInt64Int64Int64(mp map[int64]map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":"
		for k2, v2 := range v1 {
			ret += formatInt64(k2) + ":"
			for k3, v3 := range v2 {
				ret += formatInt64(k3) + ":" + formatInt64(v3) + " "
			}
		}
	}
	return ret
}

func formatMapInt64Int64Int64String(mp map[int64]map[int64]map[int64]map[int64]string) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":"
		for k2, v2 := range v1 {
			ret += formatInt64(k2) + ":"
			for k3, v3 := range v2 {
				ret += formatInt64(k3) + ":"
				for k4, v4 := range v3 {
					ret += formatInt64(k4) + ":" + formatString(v4) + " "
				}
			}
		}
	}
	return ret
}

func formatMapInt64Int64Int64Int64(mp map[int64]map[int64]map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":"
		for k2, v2 := range v1 {
			ret += formatInt64(k2) + ":"
			for k3, v3 := range v2 {
				ret += formatInt64(k3) + ":"
				for k4, v4 := range v3 {
					ret += formatInt64(k4) + ":" + formatInt64(v4) + " "
				}
			}
		}
	}
	return ret
}

func formatMapInt64Int64Int64Int64Int64(mp map[int64]map[int64]map[int64]map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":"
		for k2, v2 := range v1 {
			ret += formatInt64(k2) + ":"
			for k3, v3 := range v2 {
				ret += formatInt64(k3) + ":"
				for k4, v4 := range v3 {
					ret += formatInt64(k4) + ":" + formatInt64(v4) + " "
				}
			}
		}
	}
	return ret
}

func formatMapInt64Int64Int64Int64Int64(mp map[int64]map[int64]map[int64]map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":"
		for k2, v2 := range v1 {
			ret += formatInt64(k2) + ":" + formatInt64(v2) + " "
		}
	}
	return ret
}

func formatMapInt64Int64Int64Int64(mp map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":" + formatInt64(v1) + " "
	}
	return ret
}

func formatMapInt64Int64Int64(mp map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":" + formatInt64(v1) + " "
	}
	return ret
}

func formatMapInt64Int64(mp map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":" + formatInt64(v1) + " "
	}
	return ret
}

func formatMapInt64Int64(mp map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":" + formatInt64(v1) + " "
	}
	return ret
}

func formatMapInt64Int64(mp map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":" + formatInt64(v1) + " "
	}
	return ret
}

func formatMapInt64Int64(mp map[int64]map[int64]int64) string {
	ret := ""
	for k1, v1 := range mp {
		ret += formatInt64(k1) + ":" + formatInt64(v1) + " "
	}
	return ret
}

func formatMapIn