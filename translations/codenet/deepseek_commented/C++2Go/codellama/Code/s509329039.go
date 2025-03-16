
package main

import (
	"fmt"
	"math"
	"strconv"
)

const (
	pi   = 3.14159265358979323846264
	mod  = 1000000007
	zero = 0
	one  = 1
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
		//fmt.Println(st)
		f := one
		for j := 0; j < m; j++ {
			if st[s[j]] == c[j]+'0' {
				//do nothing
			} else {
				f = zero
			}
		}
		if f {
			fmt.Println(i)
			return
		}
	}
	fmt.Println(-1)
}

