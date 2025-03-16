package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	var lst []int
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		lst = append(lst, x)
	}
	var lst_p []int
	var lst_m []int
	for i := 0; i < N; i++ {
		if lst[i] == 0 {
			K--
		}
		if lst[i] > 0 {
			lst_p = append(lst_p, lst[i])
		} else if lst[i] < 0 {
			lst_m = append(lst_m, lst[i])
		}
	}
	var p, m int
	var x, y, lastx, lasty int
	lastx = len(lst_p)
	lasty = len(lst_m)
	check := func(k int) int {
		ans := math.MaxInt32
		for j := 0; j <= k; j++ {
			if j > lastx || k-j > lasty {
			} else {
				if j == 0 {
					p = 0
				} else {
					p = lst_p[j-1]
				}
				if k-j == 0 {
					m = 0
				} else {
					m = lst_m[lasty-(k-j)]
				}
				ans = int(math.Min(float64(ans), float64(2*p+int(math.Abs(float64(m))))))
				ans = int(math.Min(float64(ans), float64(p+2*int(math.Abs(float64(m))))))
			}
		}
		return ans
	}
	fmt.Println(check(K))
}

