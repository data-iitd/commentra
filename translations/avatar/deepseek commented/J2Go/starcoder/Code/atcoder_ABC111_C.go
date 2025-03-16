
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	v := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		v[i], _ = strconv.Atoi(sc.Text())
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
	sort.Slice(vo, func(i, j int) bool { return vo[i] > vo[j] })
	sort.Slice(ve, func(i, j int) bool { return ve[i] > ve[j] })
	sort.Slice(vt, func(i, j int) bool { return vt[i] > vt[j] })
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

