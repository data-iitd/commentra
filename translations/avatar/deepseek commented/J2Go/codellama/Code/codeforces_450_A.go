
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 0)
	var n, m int
	var err error
	fmt.Scan(&n, &m)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		sc = append(sc, x)
	}
	ans := 0
	for len(sc) > 0 {
		if sc[0] <= m {
			sc = sc[1:]
			ans = i
		} else if sc[0] > m {
			x := sc[0]
			sc[0] = x - m
			sc = append(sc, sc[0])
			sc = sc[1:]
		}
	}
	fmt.Println(ans)
}

