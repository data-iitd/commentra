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
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	X, _ := strconv.ParseInt(sc.Text(), 10, 64)
	x := make([]int64, N)
	xsum := make([]int64, N+1)
	for i := 0; i < N; i++ {
		sc.Scan()
		x[i], _ = strconv.ParseInt(sc.Text(), 10, 64)
		xsum[i+1] = xsum[i] + x[i]
	}
	ans := int64(0)
	for i := 0; i < N; i++ {
		cost := int64(0)
		for j := 5; j < 1000000; j += 2 {
			cost += int64(j) * (xsum[N] - xsum[N-i])
			if cost > ans {
				break
			}
			for k := N - i; k >= 0; k -= i {
				cost += int64(j) * (xsum[k] - xsum[max(k-i, 0)])
				if cost > ans {
					break
				}
			}
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

