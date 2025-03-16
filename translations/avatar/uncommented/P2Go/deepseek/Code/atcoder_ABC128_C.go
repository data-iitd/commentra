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
		var k int
		fmt.Scan(&k)
		li[i] = make([]int, k)
		for j := 0; j < k; j++ {
			fmt.Scan(&li[i][j])
		}
	}

	var p [8]int
	fmt.Scan(&p[0], &p[1], &p[2], &p[3], &p[4], &p[5], &p[6], &p[7])

	q := make(map[int]bool)
	for _, u := range li {
		for _, v := range u {
			q[v] = true
		}
	}

	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		if !q[i] {
			r[i] = true
		}
	}

	ans := 0
	for i := 0; i <= len(q); i++ {
		for s := range combinations(q, i) {
			ok := true
			for j, u := range li {
				count := 0
				for _, v := range s {
					if contains(u, v) {
						count++
					}
				}
				if count%2 != p[j] {
					ok = false
					break
				}
			}
			if ok {
				ans += 1 << len(r)
			}
		}
	}

	fmt.Println(ans)
}

func combinations(m map[int]bool, n int) <-chan map[int]bool {
	ch := make(chan map[int]bool)
	go func() {
		defer close(ch)
		var keys []int
		for k := range m {
			keys = append(keys, k)
		}
		for _, comb := range combinationsHelper(keys, n) {
			combMap := make(map[int]bool)
			for _, k := range comb {
				combMap[k] = true
			}
			ch <- combMap
		}
	}()
	return ch
}

func combinationsHelper(keys []int, n int) [][]int {
	if n == 0 {
		return [][]int{{}}
	}
	if len(keys) == 0 {
		return nil
	}
	rest := combinationsHelper(keys[1:], n-1)
	for _, comb := range rest {
		return append([][]int{keys[:1]}, comb...)
	}
	return combinationsHelper(keys[1:], n)
}

func contains(slice []int, val int) bool {
	for _, v := range slice {
		if v == val {
			return true
		}
	}
	return false
}
