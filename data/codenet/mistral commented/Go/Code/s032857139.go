package main

import (
	"fmt"
	"sort"
)

const MOD = 1000000007

func main() {
	var n, x int
	fmt.Scan(&n, &x)

	A := make([]int, n)
	for i := range A {
		fmt.Scan(&A[i])
	}

	sort.Ints(A)

	ans := 0
	i, j := 0, 0
	for j < len(A) {
		if x >= A[i] {
			ans++
			x -= A[i]
			i++
		} else {
			j++
		}
	}

	if x > 0 && len(A) == ans {
		ans--
	}

	fmt.Println(ans)
}
