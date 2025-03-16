package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	X, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	x := make([]int64, N)
	xsum := make([]int64, N+1)

	for i := 0; i < N; i++ {
		scanner.Scan()
		x[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
		xsum[i+1] = xsum[i] + x[i]
	}

	ans := X*int64(N) + 5*xsum[N]

	for i := 1; i < N; i++ {
		cost := X*int64(i) + 5*(xsum[N]-xsum[N-i])
		for j, k := 5, N-i; k >= 0; j, k = j+2, k-i {
			if cost > ans {
				break
			}
			cost += int64(j) * (xsum[k] - xsum[max(k-i, 0)])
		}
		ans = min(ans, cost)
	}

	fmt.Println(ans + int64(N)*X)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

