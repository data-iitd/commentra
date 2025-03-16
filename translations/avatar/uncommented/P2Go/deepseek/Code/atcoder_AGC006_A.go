package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	var s, t []rune
	fmt.Scan(&s)
	fmt.Scan(&t)

	if string(s) == string(t) {
		fmt.Println(n)
	} else {
		cnt := 0
		for i := 0; i < n; i++ {
			for j := 0; j < n-i; j++ {
				if s[i+j] != t[j] {
					break
				}
				if j == n-i-1 {
					cnt = n - i
				}
			}
		}
		fmt.Println(2*n - cnt)
	}
}
