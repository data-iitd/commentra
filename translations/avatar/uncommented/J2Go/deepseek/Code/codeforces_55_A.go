package main

import (
	"fmt"
)

func main() {
	var n, i, k, p int
	var flag bool
	var a [1000]int
	fmt.Scan(&n)
	i = 1
	k = 0
	p = 1
	flag = true
	for k <= n {
		i += k
		if i >= n {
			for i >= n {
				i -= n
			}
		}
		a[i]++
		k++
	}
	for i = 0; i < n; i++ {
		if a[i] == 0 {
			flag = false
			break
		}
	}
	if flag {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

