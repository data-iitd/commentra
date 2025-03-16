
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func na() []int {
	var n, x int
	fmt.Scan(&n, &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	return a
}

func main() {
	a := na()
	sort.Ints(a)
	ans := 0
	for i := 0; i < len(a); i++ {
		if a[i] > x {
			fmt.Println(0)
			return
		}
		if a[i] > x {
			x = 0
			break
		}
		x -= a[i]
		ans++
	}
	if x != 0 {
		ans--
	}
	fmt.Println(ans)
}

