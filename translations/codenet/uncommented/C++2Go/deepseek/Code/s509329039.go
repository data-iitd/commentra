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
		s[i]--
	}
	for i := 0; i < 1000; i++ {
		st := strconv.Itoa(i)
		if len(st) != n {
			continue
		}
		f := 1
		for j := 0; j < m; j++ {
			if st[s[j]] == byte(c[j]+'0') {

			} else {
				f = 0
			}
		}
		if f == 1 {
			fmt.Println(st)
			return
		}
	}
	fmt.Println(-1)
}

