package main

import (
	"fmt"
)

func check(n int, wei int, book []int) bool {
	tmp := wei
	n--
	for i := 0; i < len(book); i++ {
		if tmp < book[i] {
			if n > 0 {
				n--
				tmp = wei
				if tmp < book[i] {
					return false
				}
			} else {
				return false
			}
		}
		tmp -= book[i]
	}
	return true
}

func main() {
	var m, n int
	for {
		if _, err := fmt.Scan(&m, &n); err != nil || m == 0 {
			break
		}
		book := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&book[i])
		}

		l, r := 0, 1500000
		var ans int
		for l < r {
			mid := (l + r) / 2
			if check(m, mid, book) {
				ans = mid
				if r == mid {
					break
				}
				r = mid
			} else {
				if l == mid {
					break
				}
				l = mid
			}
		}
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
