package main

import (
	"fmt"
)

func main() {
	var n, i, k int
	flag := true
	a := make([]int, 1000)

	fmt.Scan(&n)
	i = 0
	k = 0

	for k <= n {
		i += k
		if i >= n {
			for !(i < n) {
				i = i - n
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

// <END-OF-CODE>
