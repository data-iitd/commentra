package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	lst := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&lst[i])
	}

	var lstP, lstM []int
	for i := 0; i < N; i++ {
		if lst[i] == 0 {
			K--
		}
		if lst[i] > 0 {
			lstP = append(lstP, lst[i])
		} else if lst[i] < 0 {
			lstM = append(lstM, lst[i])
		}
	}

	sort.Ints(lstP)
	sort.Ints(lstM)

	lastX := len(lstP)
	lastY := len(lstM)

	check := func(k int) int {
		ans := math.MaxInt32
		for j := 0; j <= k; j++ {
			if j > lastX || k-j > lastY {
				continue
			}
			var p, m int
			if j == 0 {
				p = 0
			} else {
				p = lstP[j-1]
			}
			if k-j == 0 {
				m = 0
			} else {
				m = lstM[lastY-(k-j)]
			}
			ans = min(ans, 2*p+abs(m), p+2*abs(m))
		}
		return ans
	}

	fmt.Println(check(K))
}

func min(values ...int) int {
	minVal := values[0]
	for _, v := range values {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>
