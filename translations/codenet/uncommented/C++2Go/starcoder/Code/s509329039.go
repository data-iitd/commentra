package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d\n", &n, &m)
	s := make([]int, m)
	c := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %d\n", &s[i], &c[i])
		s[i]--
	}
	for i := 0; i < 1000; i++ {
		st := strconv.Itoa(i)
		if len(st)!= n {
			continue
		}
		f := true
		for j := 0; j < m; j++ {
			if st[s[j]]!= c[j]+'0' {
				f = false
			}
		}
		if f {
			fmt.Println(i)
			return
		}
	}
	fmt.Println(-1)
}

