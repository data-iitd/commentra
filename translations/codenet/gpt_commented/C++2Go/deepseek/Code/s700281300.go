package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)

		st := make(map[string]bool)
		st[s] = true

		for j := 1; j < len(s); j++ {
			res := s[:j]
			res2 := s[j:]

			revRes := reverse(res)
			revRes2 := reverse(res2)

			st[res+res2] = true
			st[res2+res] = true
			st[res+revRes2] = true
			st[revRes2+res] = true
			st[revRes+res2] = true
			st[res2+revRes] = true
			st[revRes+revRes2] = true
			st[revRes2+revRes] = true
		}

		fmt.Println(len(st))
	}
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

