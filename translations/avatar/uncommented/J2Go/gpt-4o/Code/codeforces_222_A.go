package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	l := 0
	c := 1

	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		if a == l {
			c += 1
		} else {
			c = 1
		}
		l = a
	}

	if c+k > n {
		fmt.Println(n - c)
	} else {
		fmt.Println(-1)
	}
}

// <END-OF-CODE>
