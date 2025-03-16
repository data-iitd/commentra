package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	ans := 0
	ok := true

	for ok {
		for i := 0; i < n; i++ {
			if a[i]%2 == 1 {
				fmt.Println(ans)
				return
			} else {
				a[i] /= 2
			}
		}
		ans++
		ok = false
	}

	fmt.Println(ans)
}

