
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_N = 4000
	LINF  = 1 << 60
)

var (
	wis     [MAX_N]int64
	wsums   [MAX_N + 1]int64
	dp      [MAX_N][MAX_N + 1]int64
	ks      [MAX_N][MAX_N + 1]int
	n       int
	sc      = bufio.NewScanner(os.Stdin)
)

func main() {
	sc.Scan()
	n = int(readNum(sc.Bytes()))

	wsums[0] = 0
	for i := 0; i < n; i++ {
		sc.Scan()
		wis[i] = readNum(sc.Bytes())
		wsums[i+1] = wsums[i] + wis[i]
	}

	for i := 0; i < n; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = LINF
			ks[i][j] = -1
		}
		dp[i][i+1] = 0
		ks[i][i+1] = i
	}

	for l := 2; l <= n; l++ {
		for i := 0, j := l; j <= n; i, j = i+1, j+1 {
			mind := LINF
			wsum := wsums[j] - wsums[i]
			mink := -1
			for k := ks[i][j-1]; k <= ks[i+1][j]; k++ {
				d := dp[i][k] + dp[k][j] + wsum
				if d < mind {
					mind = d
					mink = k
				}
			}
			dp[i][j] = mind
			ks[i][j] = mink
		}
	}

	fmt.Println(dp[0][n])
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

func readNum(bytes []byte) (val int) {
	val = 0
	i := 0
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		val = val*10 + int(bytes[i]-'0')
		i++
	}
	val *= sign
	return
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
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
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(n, A)
		fmt.Println(res)
	}
}

func solve(n int, A []int) int64 {
	dp := make([][]int64, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int64, n)
	}

	for i := 0; i < n; i++ {
		dp[i][i] = int64(A[i])
	}

	for l := 2; l <= n; l++ {
		for i := 0; i+l <= n; i++ {
			j := i + l - 1
			dp[i][j] = 1 << 60
			for k := i; k < j; k++ {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+int64(A[i-1]*A[k]*A[j]))
			}
		}
	}

	return dp[0][n-1]
}

func min(a, b int64) int64 {
	if a <= b {
		return a
	}
	return b
}