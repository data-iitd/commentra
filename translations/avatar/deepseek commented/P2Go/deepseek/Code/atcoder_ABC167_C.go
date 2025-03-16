package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)

	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Scan(&c[i][j])
		}
	}

	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}

	l := [][]int{}
	rem := []int{}
	var ans int

	for i := 1; i <= n; i++ {
		for _, comb := range combinations(pre, i) {
			l = append(l, comb)
		}
	}

	for i := 1; i <= m; i++ {
		for j, k := range l {
			ca := 0
			for _, ii := range k {
				ca += c[ii][i]
			}
			if ca < x {
				rem = append(rem, j)
			}
		}
		if len(rem) > 0 {
			sort.Sort(sort.Reverse(sort.IntSlice(rem)))
			for _, j := range rem {
				l = append(l[:j], l[j+1:]...)
			}
			rem = []int{}
		}
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}

	for _, i := range l {
		ca := 0
		for _, j := range i {
			ca += c[j][0]
		}
		if ans == 0 || ca < ans {
			ans = ca
		}
	}
	fmt.Println(ans)
}

func combinations(arr []int, size int) [][]int {
	var result [][]int
	var generate func([]int, int)
	generate = func(arr []int, size int) {
		if size == 0 {
			comb := make([]int, len(arr))
			copy(comb, arr)
			result = append(result, comb)
			return
		}
		if len(arr) == 0 {
			return
		}
		generate(arr[1:], size-1)
		generate(arr[1:], size)
	}
	generate(arr, size)
	return result
}

