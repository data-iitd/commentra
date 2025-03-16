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
	len  = 1e6 + 1
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N := parseInt(scanner.Text())
	scanner.Scan()
	K := parseInt64(scanner.Text())

	A := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		A[i] = parseInt(scanner.Text()) - 1
	}

	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)

	next, cur := 0, 0

	for !used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := (int64(10000)*a + K - b) % a + b

	if b > K {
		ans = K
	}

	fmt.Println(pos[ans] + 1)
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

func parseInt64(s string) int64 {
	var res int64
	fmt.Sscanf(s, "%d", &res)
	return res
}

