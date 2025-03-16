package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var l, r int
	fmt.Scan(&l, &r)

	curr := r
	s := 0
	ans := -1

	for curr != 0 {
		s++
		first := int(math.Pow(10, float64(s)))
		second := first / 2

		for _, i := range []int{l, r, first, second} {
			if i >= l && i <= r {
				curr = i
				rev := ""

				for _, k := range strconv.Itoa(curr) {
					digit := int(k - '0')
					rev += strconv.Itoa(9 - digit)
				}

				reversedNum, _ := strconv.Atoi(rev)
				ans = max(ans, reversedNum*curr)
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
