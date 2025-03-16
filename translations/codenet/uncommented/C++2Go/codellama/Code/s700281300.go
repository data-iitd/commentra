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

			t := res
			res = strings.Reverse(res)
			t2 := res2
			res2 = strings.Reverse(res2)

			st[t+t2] = true
			st[t2+t] = true

			st[t+res2] = true
			st[res2+t] = true

			st[res+t2] = true
			st[t2+res] = true

			st[res+res2] = true
			st[res2+res] = true
		}

		fmt.Println(len(st))
	}
}

