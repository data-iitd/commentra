
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Ints(a)
	for i := 0; i < len(a)-1; i++ {
		if a[i+1] < a[i]*2 && a[i] != a[i+1] {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}

