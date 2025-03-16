package main

import (
	"fmt"
	"sort"
)

func main() {
	var tc, n, m int
	fmt.Scan(&tc, &n, &m)
	if n > m {
		n, m = m, n
	}
	for i := 1; i <= m; i++ {
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}

