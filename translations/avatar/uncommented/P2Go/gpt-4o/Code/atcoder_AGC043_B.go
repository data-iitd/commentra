package main

import (
	"fmt"
)

func twosInFactorial(n int) int {
	count := 0
	for n > 0 {
		count += n / 2
		n /= 2
	}
	return count
}

func parityOfNCr(n, i int) bool {
	f := twosInFactorial
	return f(n) - f(n-i) - f(i) > 0
}

func main() {
	var n int
	fmt.Scan(&n)
	
	var nums []int
	var input int
	for i := 0; i < n; i++ {
		fmt.Scan(&input)
		nums = append(nums, input-1)
	}

	noOne := false
	for _, num := range nums {
		if num == 1 {
			noOne = false
			break
		}
	}

	if !noOne {
		for i := range nums {
			nums[i] /= 2
		}
		noOne = true
	}

	isOdd := false
	for i, num := range nums {
		if !parityOfNCr(n-1, i) && num&1 == 1 {
			isOdd = !isOdd
		}
	}

	if !isOdd {
		fmt.Println(0)
	} else {
		if noOne {
			fmt.Println(1)
		} else {
			fmt.Println(2)
		}
	}
}

// <END-OF-CODE>
