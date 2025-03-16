package main

import (
	"fmt"
)

func main() {
	var tc, n, m, fl int
	fmt.Scan(&tc, &n, &m)
	if n > m {
		n, m = m, n
	}
	for i := 1; i <= m; i++ {
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK")
			fl = 1
			break
		}
	}
	if fl == 0 {
		fmt.Println("NG")
	}
}

