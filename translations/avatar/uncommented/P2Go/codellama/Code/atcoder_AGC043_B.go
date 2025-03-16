package main

import (
	"fmt"
	"strconv"
	"strings"
)

func twos_in_factorial(n int) int {
	return n - strings.Count(strconv.FormatInt(int64(n), 2), "1")
}

func parity_of_nCr(n, i int) bool {
	f := twos_in_factorial
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	for i := range nums {
		fmt.Scan(&nums[i])
		nums[i]--
	}
	no_one := false
	if !contains(nums, 1) {
		for i := range nums {
			nums[i] /= 2
		}
		no_one = true
	}
	is_odd := false
	for i, num := range nums {
		if !parity_of_nCr(n-1, i) && num&1 == 1 {
			is_odd = !is_odd
		}
	}
	if !is_odd {
		fmt.Println(0)
	} else {
		fmt.Println(1 << no_one)
	}
}

func contains(nums []int, target int) bool {
	for _, num := range nums {
		if num == target {
			return true
		}
	}
	return false
}

