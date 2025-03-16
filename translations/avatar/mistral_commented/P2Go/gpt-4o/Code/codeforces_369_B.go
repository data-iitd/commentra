package main

import (
	"fmt"
)

func getNums(num, t int) []int {
	// This function takes two arguments: an integer `num` and an integer `t`.
	// It returns a slice of integers obtained by dividing `t` by `num` and adding 1 to the quotient for each index `i` in the range of `t % num`.
	result := make([]int, num)
	quotient := t / num
	remainder := t % num
	for i := 0; i < num; i++ {
		if i < remainder {
			result[i] = quotient + 1
		} else {
			result[i] = quotient
		}
	}
	return result
}

func main() {
	var n, k, l, r, sa, sk int
	fmt.Scan(&n, &k, &l, &r, &sa, &sk)
	// This line reads five integers from the standard input and assigns them to the variables `n`, `k`, `l`, `r`, `sa`, and `sk`.

	ans := append(getNums(k, sk), getNums(n-k, sa-sk)...)
	// This line initializes the variable `ans` as the sum of two slices: the result of calling `getNums` with arguments `k` and `sk`, and the result of calling `getNums` with arguments `n - k` and `sa - sk`.

	for i, v := range ans {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	// This line prints the elements of the slice `ans` to the standard output, separated by spaces.
}

// <END-OF-CODE>
