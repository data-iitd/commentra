package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	b := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	temp := 0
	q := 0
	w := 0
	e := 0
	f := false

	for i := 0; i < n; i++ {
		if temp < a[i] {
			if q > b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if temp > a[i] {
			if q < b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if a[i] > w {
			w = a[i]
			if b[i] < e {
				f = true
			}
			e = b[i]
		}
		if a[i] < w {
			if b[i] > e {
				f = true
			}
		}
	}

	if f {
		fmt.Println("Happy Alex")
	} else {
		fmt.Println("Poor Alex")
	}
}

