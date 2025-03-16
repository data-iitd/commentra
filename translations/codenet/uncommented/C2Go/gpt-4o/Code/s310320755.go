package main

import (
	"fmt"
)

func main() {
	var n int
	arr := make([][]int, 17) // Create a 2D slice with size 17 for 1-based indexing
	for i := range arr {
		arr[i] = make([]int, 17)
	}

	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		flag := 1
		r := (n + 1) / 2 + 1
		c := (n + 1) / 2
		arr[r][c] = 1
		cnt := 1

		for cnt != n*n {
			cnt++
			if flag == 1 {
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

		for r = 1; r <= n; r++ {
			for c = 1; c <= n; c++ {
				fmt.Printf("%4d", arr[r][c])
				arr[r][c] = 0
				if c == n {
					fmt.Println()
				}
			}
		}
	}
}

// <END-OF-CODE>
