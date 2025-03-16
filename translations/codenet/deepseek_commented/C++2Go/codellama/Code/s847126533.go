package main

import (
	"fmt"
	"sort"
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
		fmt.Scan(&m, &n)
		if m == 0 {
			break
		}
		book := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&book[i])
		}
		sort.Ints(book)

		// Binary search to find the maximum weight a person can carry
		l := 0
		r := 1500000
		var ans int
		for l < r {
			mid := (l + r) / 2
			if check(m, mid, book) {
				ans = mid
				r = mid // Adjust the right boundary
			} else {
				l = mid // Adjust the left boundary
			}
		}
		fmt.Println(ans)
	}
}

