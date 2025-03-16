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

	lst_p := []int{}
	lst_m := []int{}

	// Separating positive and negative numbers
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

	// Initialization of pointers and variables
	p := 0
	m := 0
	x, y := 0, len(lst_m)-1
	lastx := len(lst_p)
	lasty := len(lst_m)

	// Function to check the minimum possible value
	check := func(k int) int {
		ans := int(math.Pow(10, 9))
		for j := 0; j <= k; j++ {
			if j > lastx || k-j > lasty {
				continue
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
				ans = int(math.Min(float64(ans), math.Min(float64(2*p+int(math.Abs(float64(m)))), float64(p+2*int(math.Abs(float64(m)))))))
			}
		}
		return ans
	}

	// Output the result of the check function with K as the argument
	fmt.Println(check(K))
}
