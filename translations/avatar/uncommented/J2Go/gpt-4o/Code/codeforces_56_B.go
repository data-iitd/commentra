package main

import (
	"fmt"
)

func main() {
	var len int
	fmt.Scan(&len)
	a := make([]int, len)

	for i := 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	l, r := 0, 0
	flag := false
	isTrue := false

loop:
	for i := 0; i < len; i++ {
		if a[i] != i+1 && !flag {
			l = i + 1
			flag = true
			continue
		}
		if a[i] != i+1 && flag {
			r = i + 1
			if a[r-1]-a[r-2] > 0 {
				isTrue = true
				break loop
			}
		}
	}

	if !isTrue {
		fmt.Printf("%d %d\n", l, r)
	} else {
		fmt.Println("0 0")
	}
}

// <END-OF-CODE>
