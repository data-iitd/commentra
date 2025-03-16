package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	v := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&v[i])
	}

	vo := make([]int, 100010)
	ve := make([]int, 100010)
	vt := make([]int, 100010)

	for i := 0; i < n; i++ {
		vt[v[i]]++
		if i%2 == 0 {
			ve[v[i]]++
		} else {
			vo[v[i]]++
		}
	}

	sort.Sort(sort.Reverse(sort.IntSlice(vo)))
	sort.Sort(sort.Reverse(sort.IntSlice(ve)))
	sort.Sort(sort.Reverse(sort.IntSlice(vt)))

	var ans int
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

// <END-OF-CODE>
