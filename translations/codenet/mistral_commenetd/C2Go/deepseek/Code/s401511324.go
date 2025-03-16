package main

import (
	"fmt"
)

func main() {
	var n int
	var l [2001]int
	var i, j, k int
	var cnt int = 0
	var tmp int

	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	for i = 0; i < n-1; i++ {
		for j = i + 1; j < n; j++ {
			if l[j] < l[i] {
				tmp = l[i]
				l[i] = l[j]
				l[j] = tmp
			}
		}
	}

	for i = 0; i < n-2; i++ {
		for j = i+1; j < n-1; j++ {
			for k = j+1; k < n; k++ {
				if l[i]+l[j] > l[k] {
					cnt++
				} else {
					break
				}
			}
		}
	}

	fmt.Println(cnt)
}

