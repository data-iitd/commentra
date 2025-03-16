package main

import (
	"fmt"
	"strconv"
)

func main() {
	var l, r int
	fmt.Scan(&l, &r)
	curr := r
	s := 0
	for curr > 0 {
		s += 1
		curr /= 10
	}
	first := 10 * s
	second := first / 2
	ans := -1
	for _, i := range []int{l, r, first, second} {
		if i >= l && i <= r {
			curr = i
			rev := ""
			for _, k := range strconv.Itoa(curr) {
				rev += strconv.Itoa(9 - int(k-'0'))
			}
			reversedInt, _ := strconv.Atoi(rev)
			ans = max(ans, reversedInt*curr)
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
