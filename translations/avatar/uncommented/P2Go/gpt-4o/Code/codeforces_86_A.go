package main

import (
	"fmt"
	"math"
)

func main() {
	var l, r int
	fmt.Scan(&l, &r)
	curr := r
	s := 0

	for curr > 0 {
		s++
		curr /= 10
	}

	first := int(math.Pow(10, float64(s)))
	second := first / 2
	ans := -1

	for _, i := range []int{l, r, first, second} {
		if i >= l && i <= r {
			curr := i
			rev := ""
			for _, k := range fmt.Sprint(curr) {
				rev += fmt.Sprint(9 - int(k-'0'))
			}
			if revInt, err := strconv.Atoi(rev); err == nil {
				ans = max(ans, revInt*curr)
			}
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

// <END-OF-CODE>
