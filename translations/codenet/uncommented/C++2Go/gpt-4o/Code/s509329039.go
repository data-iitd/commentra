package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	s := make([]int, m)
	c := make([]int, m)

	for i := 0; i < m; i++ {
		fmt.Scan(&s[i], &c[i])
		s[i]-- // Adjusting for 0-based index
	}

	for i := 0; i < 1000; i++ {
		st := strconv.Itoa(i)
		if len(st) != n {
			continue
		}

		f := true
		for j := 0; j < m; j++ {
			if st[s[j]] == rune(c[j]+'0') {
				// Do nothing, condition satisfied
			} else {
				f = false
				break
			}
		}

		if f {
			fmt.Println(i)
			return
		}
	}

	fmt.Println(-1)
}

// <END-OF-CODE>
