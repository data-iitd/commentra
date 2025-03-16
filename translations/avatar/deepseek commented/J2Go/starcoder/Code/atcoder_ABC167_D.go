
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	var N, K int
	var A []int

	N = nextInt(sc)
	K = nextInt(sc)

	A = make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = nextInt(sc) - 1
	}

	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)

	next := 0
	cur := 0
	for!used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	a := int64(cur) - int64(idx[next])
	b := int64(idx[next])
	ans := (10000*a + K - b) % a + b
	if b > int64(K) {
		ans = int64(K)
	}

	fmt.Println(pos[ans]+1)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

