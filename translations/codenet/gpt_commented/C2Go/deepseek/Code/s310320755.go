package main

import (
	"fmt"
)

func main() {
	var n, flag, cnt int
	var arr [16][16]int

	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}

		flag = 1
		r := (n + 1) / 2
		c := (n + 1) / 2 - 1
		arr[r][c] = cnt = 1

		for cnt != n*n+1 {
			cnt++

			if flag == 1 {
				r++
				c++

				if c == n {
					c = 0
				}

				if r == n {
					r = 0
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

				if c == -1 {
					c = n - 1
				}

				if r == n {
					r = 0
				}

				if arr[r][c] != 0 {
					flag = 1
				} else {
					arr[r][c] = cnt
					flag = 1
				}
			}
		}

		for r := 0; r < n; r++ {
			for c := 0; c < n; c++ {
				fmt.Printf("%4d", arr[r][c])
				arr[r][c] = 0
			}
			fmt.Println()
		}
	}
}

