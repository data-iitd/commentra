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
		s++
		curr /= 10
	}

	first := 10 * s
	second := first / 2

	ans := -1

	for _, i := range []int{l, r, first, second} {
		if i >= l && i <= r {
			curr := i
			rev := ""

			for _, k := range strconv.Itoa(curr) {
				rev = string(rune(57-int(k))) + rev
			}

			revInt, _ := strconv.Atoi(rev)
			if product := curr * revInt; product > ans {
				ans = product
			}
		}
	}

	fmt.Println(ans)
}

