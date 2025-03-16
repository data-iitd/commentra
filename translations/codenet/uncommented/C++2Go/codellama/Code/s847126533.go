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
		/*
			for {
				var tmp int
				fmt.Scan(&tmp)
				if check(m, tmp, book) {
					fmt.Println("YES")
				} else {
					fmt.Println("NO")
				}
			}
		*/

		l := 0
		r := 1500000
		ans := 0
		for l < r {
			if check(m, (l+r)/2, book) {
				ans = (l + r) / 2
				if r == (l+r)/2 {
					break
				}
				r = (l + r) / 2
			} else {
				if l == (l+r)/2 {
					break
				}
				l = (l + r) / 2
			}
		}
		fmt.Println(ans)
	}
}

