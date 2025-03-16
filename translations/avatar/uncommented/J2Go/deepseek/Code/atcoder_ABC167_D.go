package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MOD  = 1000000007
	MAX  = int(^uint(0) >> 1)
	LMAX = int64(^uint64(0) >> 1)
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var N int
	var K int64
	var A []int

	scanner.Scan()
	fmt.Sscan(scanner.Text(), &N)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &K)

	A = make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &A[i])
		A[i]--
	}

	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)
	next := 0
	cur := 0

	for !used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := (int)((10000*a + K - b) % a + b)
	if b > K {
		ans = int(K)
	}

	fmt.Println(pos[ans] + 1)
}

