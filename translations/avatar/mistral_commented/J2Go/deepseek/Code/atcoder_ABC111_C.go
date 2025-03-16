package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	v := make([]int, 100010)
	for i := 0; i < n; i++ {
		fmt.Scan(&v[i])
	}

	vo := make([]int, 100010)
	ve := make([]int, 100010)
	vt := make([]int, 100010)

	for i := 0; i < n; i += 2 {
		vo[v[i]]++
	}

	for i := 1; i < n; i += 2 {
		ve[v[i]]++
	}

	sort.Slice(vo, func(i, j int) bool {
		return vo[i] > vo[j]
	})

	sort.Slice(ve, func(i, j int) bool {
		return ve[i] > ve[j]
	})

	sort.Slice(vt, func(i, j int) bool {
		return vt[i] > vt[j]
	})

	ans := 0

	if vo[0]+ve[0] == vt[0] {
		ans = min(n-vo[0]-ve[1], n-vo[1]-ve[0])
	} else {
		ans = n - vo[0] - ve[0]
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

