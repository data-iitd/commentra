package main

import (
	"fmt"
	"math"
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
	ans := math.MaxInt32

	for i := 1; i <= n; i++ {
		combinations := combinations(pre, i)
		l = append(l, combinations...)
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
			sort.Sort(sort.Reverse(sort.IntSlice(rem))) // Sort in reverse to remove elements safely
			for _, j := range rem {
				l = append(l[:j], l[j+1:]...) // Remove element at index j
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
		if ans == math.MaxInt32 {
			ans = ca
		} else {
			ans = int(math.Min(float64(ans), float64(ca)))
		}
	}
	fmt.Println(ans)
}

// Helper function to generate combinations
func combinations(arr []int, r int) [][]int {
	var result [][]int
	var comb []int
	var backtrack func(start int)
	backtrack = func(start int) {
		if len(comb) == r {
			combCopy := make([]int, r)
			copy(combCopy, comb)
			result = append(result, combCopy)
			return
		}
		for i := start; i < len(arr); i++ {
			comb = append(comb, arr[i])
			backtrack(i + 1)
			comb = comb[:len(comb)-1]
		}
	}
	backtrack(0)
	return result
}

// <END-OF-CODE>
