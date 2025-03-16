package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	var l, r int
	fmt.Scan(&l, &r)

	id := 0
	for i := 1; i < n; i++ {
		var li, ri int
		fmt.Scan(&li, &ri)

		if li <= l && r <= ri {
			id = i
		} else if li < l || r < ri {
			id = n
		}
		l = int(math.Min(float64(l), float64(li)))
		r = int(math.Max(float64(r), float64(ri)))
	}

	if id == n {
		fmt.Println(-1)
	} else {
		fmt.Println(id + 1)
	}
}

// <END-OF-CODE>
