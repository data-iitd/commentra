package main

import (
	"fmt"
	"math/big"
	"strconv"
)

func twosInFactorial(n int) int {
	binary := strconv.FormatInt(int64(n), 2)
	return n - len(binary)
}

func parityOfNCR(n, i int) bool {
	f := twosInFactorial
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	var n int
	fmt.Scan(&n)

	var nums []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		nums = append(nums, num-1)
	}

	noOne := false
	if !contains(nums, 1) {
		for i := range nums {
			nums[i] /= 2
		}
		noOne = true
	}

	isOdd := false
	for i, num := range nums {
		if !parityOfNCR(n-1, i) && num&1 == 1 {
			isOdd = !isOdd
		}
	}

	if !isOdd {
		fmt.Println(0)
	} else {
		fmt.Println(1 << noOne)
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
