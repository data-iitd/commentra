package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var X int64
	fmt.Scan(&N, &X)
	x := make([]int64, N)
	xsum := make([]int64, N+1)
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
		xsum[i+1] = xsum[i] + x[i]
	}
	ans := X*int64(N) + 5*xsum[N]
	for i := 1; i < N; i++ {
		cost := X*int64(i) + 5*(xsum[N]-xsum[N-i])
		for j, k := 5, N-i; k >= 0; j, k = j+2, k-i {
			if cost > ans {
				break
			}
			cost += int64(j) * (xsum[k] - xsum[int(math.Max(float64(k-i), 0))])
		}
		ans = int64(math.Min(float64(ans), float64(cost)))
	}
	fmt.Println(ans + N*X)
}

