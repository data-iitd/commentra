package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	var lst []int
	for i := 0; i < N; i++ {
		var num int
		fmt.Scan(&num)
		lst = append(lst, num)
	}

	var lstP, lstM []int
	for _, num := range lst {
		if num == 0 {
			K--
		} else if num > 0 {
			lstP = append(lstP, num)
		} else {
			lstM = append(lstM, num)
		}
	}

	lastX := len(lstP)
	lastY := len(lstM)

	check := func(k int) int {
		ans := math.MaxInt64

		for j := 0; j <= k; j++ {
			if j > lastX || k-j > lastY {
				continue
			}

			var p int
			if j == 0 {
				p = 0
			} else {
				p = lstP[j-1]
			}

			var m int
			if k-j == 0 {
				m = 0
			} else {
				m = lstM[lastY-(k-j)]
			}

			ans = min(ans, 2*p+int(math.Abs(float64(m))), p+2*int(math.Abs(float64(m))))
		}

		return ans
	}

	fmt.Println(check(K))
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
	} else {
		if b < c {
			return b
		}
	}
	return c
}
