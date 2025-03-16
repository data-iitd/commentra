package main

import (
	"fmt"
)

func getNums(num, t int) []int {
	result := make([]int, num)
	for i := 0; i < num; i++ {
		if i < t%num {
			result[i] = t/num + 1
		} else {
			result[i] = t / num
		}
	}
	return result
}

func main() {
	var n, k, l, r, sa, sk int
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)

	ans := append(getNums(k, sk), getNums(n-k, sa-sk)...)

	for i, v := range ans {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

// <END-OF-CODE>
