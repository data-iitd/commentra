package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	f := 0
	a := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var k, j, i int
	for k = 0; k < n; k++ {
		t := a[k]
		for i = 0; i < n; i++ {
			for j = 0; j < n; j++ {
				if i != j && t == (a[i]+a[j]) {
					f = 1
					break
				}
			}
			if f == 1 {
				break
			}
		}
		if f == 1 {
			break
		}
	}

	if f == 1 {
		fmt.Println(k+1, j+1, i+1)
	} else {
		fmt.Println("-1")
	}
}

// <END-OF-CODE>
