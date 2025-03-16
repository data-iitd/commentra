package main

import (
	"fmt"
	"strconv"
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

	result := ""
	for i, v := range ans {
		if i > 0 {
			result += " "
		}
		result += strconv.Itoa(v)
	}
	fmt.Println(result)
}
