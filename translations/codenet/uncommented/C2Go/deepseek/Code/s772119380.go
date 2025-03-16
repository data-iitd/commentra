package main

import (
	"fmt"
)

func main() {
	var a [1000]int
	var n, i, j, d int
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i = 0; i < n; i++ {
		for j = n - 1; j >= i+1; j-- {
			if a[j] < a[j-1] {
				var temp int = a[j]
				a[j] = a[j-1]
				a[j-1] = temp
				d++
			}
		}
	}
	fmt.Print(a[0])
	for i = 1; i < n; i++ {
		fmt.Print(" ", a[i])
	}
	fmt.Println()
	fmt.Println(d)
}

