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

	f := 0
	for k := 0; k < n; k++ {
		t := a[k]
		for i := 0; i < n; i++ {
			if i != k {
				for j := 0; j < n-1; j++ {
					if i != j && t == (a[i]+a[j]) {
						f = 1
						break
					}
				}
				if f == 1 {
					break
				}
			}
		}
		if f == 1 {
			fmt.Println(k+1, i+1, j+1)
			f = 0
		}
	}

	if f == 0 {
		fmt.Println(-1)
	}
}
