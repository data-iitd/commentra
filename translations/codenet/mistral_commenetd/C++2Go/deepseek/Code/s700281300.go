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

		for j := 1; j < len(s); j++ {
			for k := 0; k < j; k++ {
				res := s[:j]
				res2 := s[j:]

				t := res
				t2 := res2

				reversedRes := reverse(res)
				reversedRes2 := reverse(res2)

				st[t+t2] = true
				st[t2+t] = true
				st[t+reversedRes2] = true
				st[reversedRes2+t] = true
				st[reversedRes+t2] = true
				st[t2+reversedRes] = true
				st[reversedRes+reversedRes2] = true
				st[reversedRes2+reversedRes] = true
			}
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

