
package main

import (
	"fmt"
	"sort"
	"strconv"
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

	for i := 0; i < 100010; i++ {
		vo[i] = 0
		ve[i] = 0
		vt[i] = 0
	}

	for i := 0; i < n; i += 2 {
		vo[v[i]]++
	}

	for i := 1; i < n; i += 2 {
		ve[v[i]]++
	}

	sort.Sort(sort.Reverse(sort.IntSlice(vo)))
	sort.Sort(sort.Reverse(sort.IntSlice(ve)))
	sort.Sort(sort.Reverse(sort.IntSlice(vt)))

	ans := 0
	if vo[0]+ve[0] == vt[0] {
		ans = int(math.Min(float64(n-vo[0]-ve[1]), float64(n-vo[1]-ve[0])))
	} else {
		ans = n - vo[0] - ve[0]
	}

	fmt.Println(ans)
}

// 