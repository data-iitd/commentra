package main

import (
	"fmt"
)

func main() {
	var n, r, c, cnt, flag int
	arr := make([][]int, 16)
	for i := range arr {
		arr[i] = make([]int, 16)
	}

	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}

		flag = 1
		r = (n + 1) / 2 + 1
		c = (n + 1) / 2
		arr[r][c] = cnt = 1

		for cnt != n*n+1 {
			cnt++
			if flag {
				r++
				c++
				if c > n {
					c = 1
				}
				if r > n {
					r = 1
				}
				if arr[r][c] != 0 {
					flag = 0
					cnt--
				} else {
					arr[r][c] = cnt
				}
			} else {
				r++
				c--
				if c < 1 {
					c = n
				}
				if r > n {
					r = 1
				}
				if arr[r][c] != 0 {
					flag = 0
				} else {
					arr[r][c] = cnt
					flag = 1
				}
			}
		}

		for r = 1; r < n+1; r++ {
			for c = 1; c < n+1; c++ {
				fmt.Printf("%4d", arr[r][c])
				arr[r][c] = 0
				if c == n {
					fmt.Println()
				}
			}
		}
	}
}

