package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 0)
	n, _ := strconv.Atoi(os.Args[1])
	m, _ := strconv.Atoi(os.Args[2])
	for i := 1; i <= n; i++ {
		sc = append(sc, i)
	}
	ans := 0
	for len(sc) > 0 {
		if sc[0] <= m {
			ans = sc[0]
			sc = sc[1:]
		} else if sc[0] > m {
			x := sc[0]
			val := x - m
			sc[0] = val
			sc = append(sc, sc[1:]...)
		}
	}
	fmt.Println(ans)
}

