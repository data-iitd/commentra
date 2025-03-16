
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const MOD = 100000007
	const dx = [4]int{1, 0, -1, 0}
	const dy = [4]int{0, 1, 0, -1}
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)
	N, _ := strconv.Atoi(sc.Text())
	X, _ := strconv.Atoi(sc.Text())
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(sc.Text())
	}
	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}
	ans := 1 << 60
	for k := 1; k <= N; k++ {
		E := int64(k*X + 2*S[N-2*k-1])
		ans = min(ans, E)
	}
	fmt.Println(ans + int64(N*X+5*S[N-1]))
}

func min(x, y int64) int64 {
	if x < y {
		return x
	} else {
		return y
	}
}

