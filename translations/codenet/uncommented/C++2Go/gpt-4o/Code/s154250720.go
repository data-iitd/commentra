package main

import (
	"fmt"
	"sort"
)

const maxn = 200000 + 10

func main() {
	var n int
	for {
		if _, err := fmt.Scan(&n); err != nil {
			break
		}
		maps := make([]int, maxn)
		num := make([]int, maxn)

		for i := 1; i <= n; i++ {
			fmt.Scan(&maps[i])
			num[i] = maps[i]
		}

		sort.Ints(maps[1:n+1])
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

// <END-OF-CODE>
