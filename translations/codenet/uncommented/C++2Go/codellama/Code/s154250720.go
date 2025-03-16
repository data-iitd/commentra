package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		maps := make([]int, n+1)
		num := make([]int, n+1)
		for i := 1; i <= n; i++ {
			fmt.Scanf("%d", &maps[i])
			num[i] = maps[i]
		}
		sort.Ints(maps)
		m := n / 2
		for i := 1; i <= n; i++ {
			if num[i] <= maps[m] {
				fmt.Println(maps[m+1])
			} else {
				fmt.Println(maps[m])
			}
		}
	}
}

