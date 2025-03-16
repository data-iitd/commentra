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
		var tmp int
		fmt.Scan(&tmp)
		lst = append(lst, tmp)
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
	p := 0
	m := 0
	x := 0
	y := len(lst_m) - 1
	lastx := len(lst_p)
	lasty := len(lst_m)
	check := func(k int) int {
		ans := math.MaxInt32
		for j := 0; j < k+1; j++ {
			if j > lastx || k-j > lasty {
				continue
			}
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
		return ans
	}
	fmt.Println(check(K))
}

// 