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
		first := 10 * s
		second := first / 2
		ans := -1

		for _, i := range []int{l, r, first, second} {
			if i >= l && i <= r {
				curr = i
				rev := ""
				for _, k := range strconv.Itoa(curr) {
					rev = string(rune(57-int(k)+48)) + rev
				}
				revInt, _ := strconv.Atoi(rev)
				if ans < revInt*curr {
					ans = revInt * curr
				}
			}
		}
	}

	fmt.Println(ans)
}

