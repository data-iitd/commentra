package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		li[i] = make([]int, n)
		fmt.Scan(&li[i][0])
		for j := 1; j < n; j++ {
			fmt.Scan(&li[i][j])
		}
	}
	var p string
	fmt.Scan(&p)
	q := make([]int, 0)
	for _, v := range strings.Split(p, " ") {
		v, _ := strconv.Atoi(v)
		q = append(q, v)
	}
	r := make([]int, n)
	for i := 0; i < n; i++ {
		r[i] = i + 1
	}
	v := make([]int, 0)
	for _, v := range r {
		if !contains(q, v) {
			v = append(v, v)
		}
	}
	ans := 0
	for i := 0; i < len(q)+1; i++ {
		for _, s := range combinations(q, i) {
			for _, u := range li {
				s := make([]int, len(s))
				copy(s, s)
				if len(s) == 0 {
					break
				}
				for _, v := range u {
					if !contains(s, v) {
						break
					}
				}
				if len(s) == 0 {
					break
				}
			}
			ans += 2 << len(v)
		}
	}
	fmt.Println(ans)
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func combinations(s []int, r int) [][]int {
	var combs [][]int
	if r == 0 {
		return combs
	}
	if r == 1 {
		for _, v := range s {
			combs = append(combs, []int{v})
		}
		return combs
	}
	for i := 0; i < len(s); i++ {
		for _, v := range combinations(s[i+1:], r-1) {
			combs = append(combs, append([]int{s[i]}, v...))
		}
	}
	return combs
}

// 