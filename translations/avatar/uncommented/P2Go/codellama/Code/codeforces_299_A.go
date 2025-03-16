
package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Ints(a)
	if a[0] == 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(a[0])
	}
}

