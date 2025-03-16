package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &a[i])
	}

	ans := 0
	ok := true
	for ok {
		for i := 0; i < n; i++ {
			if a[i]%2 == 1 {
				fmt.Println(ans)
				return
			}
			a[i] /= 2
		}
		ans++
	}

	fmt.Println(ans)
}

