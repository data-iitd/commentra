
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	v := make([]int, n)
	for i := 0; i < n; i++ {
		v[i], _ = strconv.Atoi(reader.ReadLine()[2:])
	}
	vo := make([]int, 100010)
	ve := make([]int, 100010)
	vt := make([]int, 100010)
	for i := 0; i < 100010; i++ {
		vo[i] = 0
		ve[i] = 0
		vt[i] = 0
	}
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

