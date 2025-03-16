package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	if n == 0 {
		if m != 0 {
			fmt.Println("Impossible")
		} else {
			fmt.Println("0 0")
		}
		return
	}

	if m <= n {
		if m == 0 {
			m = 1
		}
		fmt.Printf("%d %d", n, m+n-1)
		return
	}

	fmt.Printf("%d %d", m, m+n-1)
}

