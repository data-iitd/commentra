package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	m := make(map[int]string)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		m[i] = s
	}
	ans := true
	past := make(map[int]string)
	next := ""
	for i := 0; i < N; i++ {
		if _, ok := past[i]; ok {
			ans = false
			break
		}
		past[i] = m[i]
		if i != 0 {
			if !strings.HasPrefix(m[i], next) {
				ans = false
				break
			}
		}
		next = m[i][len(m[i])-1:]
	}
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

