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

	lst_p := []int{}
	lst_m := []int{}
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

	sort.Ints(lst_p)
	sort.Ints(lst_m)

	lastx := len(lst_p)
	lasty := len(lst_m)

	check := func(k int) int {
		ans := int(math.Pow(10, 9))
		for j := 0; j <= k; j++ {
			if j > lastx || k-j > lasty {
				continue
			}
			var p, m int
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
			ans = min(ans, 2*p+int(math.Abs(float64(m))), p+2*int(math.Abs(float64(m))))
		}
		return ans
	}

	fmt.Println(check(K))
}

func min(args ...int) int {
	min := args[0]
	for _, v := range args {
		if v < min {
			min = v
		}
	}
	return min
}

