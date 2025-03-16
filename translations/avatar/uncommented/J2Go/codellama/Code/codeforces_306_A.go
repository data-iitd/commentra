
package main

import (
	"fmt"
	"os"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, m)
	if n%m == 0 {
		for i := 0; i < len(a); i++ {
			a[i] = n / m
		}
	} else {
		sub := n / m
		for i := 0; i < len(a); i++ {
			a[i] = sub
		}
		test := n - (sub * m)
		count := 0
		for i := 0; i < test; i++ {
			a[count] = a[count] + 1
			count++
			if count > len(a) {
				count = 0
			}
		}
	}
	for i := len(a) - 1; i >= 0; i-- {
		fmt.Printf("%d ", a[i])
	}
}

