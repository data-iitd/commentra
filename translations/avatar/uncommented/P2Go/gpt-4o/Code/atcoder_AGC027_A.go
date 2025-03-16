package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	sort.Ints(a)

	ans := 0
	if a[0] > x {
		fmt.Println(0)
		return
	}

	for _, i := range a {
		if i > x {
			x = 0
			break
		}
		x -= i
		ans++
	}

	if x != 0 {
		ans--
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
