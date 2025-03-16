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
	isup := false
	issame := false
	if a[0] < a[1] {
		isup = true
	} else if a[0] > a[1] {
		isup = false
	} else {
		issame = true
	}
	cnt := 1
	for i := 1; i < n-1; i++ {
		if issame {
			if a[i] != a[i+1] {
				issame = false
				if a[i] < a[i+1] {
					isup = true
				} else {
					isup = false
				}
			}
		} else {
			if isup && a[i] <= a[i+1] {
				;
			} else if !isup && a[i] >= a[i+1] {
				;
			} else {
				if i+2 < n {
					if a[i+1] < a[i+2] {
						isup = true
					} else if a[i+1] > a[i+2] {
						isup = false
					} else {
						issame = true
					}
					cnt++
				} else {
					cnt++
					break
				}
			}
		}
	}
	fmt.Println(cnt)
}

