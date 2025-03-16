
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007
const MAX = int(1e6 + 1)
const LMAX = int64(1e18 + 1)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	N := nextInt(sc)
	K := nextInt64(sc)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = nextInt(sc) - 1
	}
	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)
	next, cur := 0, 0
	for!used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}
	a, b := int64(cur)-int64(idx[next]), int64(idx[next])
	ans := (10000*a+K-b)%a + b
	if b > K {
		ans = K
	}
	fmt.Println(pos[ans]+1)
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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}
	return n
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, err := strconv.ParseInt(sc.Text(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return n
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

func abs(x, y int64) int64 {
	return maxInt64(x, y)-minInt64(x, y)
}

func pow(x, n int64) int64 {
	ret := int64(1)
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func mod(x, m int64) int64 {
	return (x % m + m) % m
}

func isDebug() bool {
	_, ok := os.LookupEnv("DEBUG")
	return ok
}

func printf(format string, a...interface{}) {
	fmt.Printf(format, a...)
}

func printfDebug(format string, a...interface{}) {
	if isDebug() {
		fmt.Printf(format, a...)
	}
}