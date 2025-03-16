package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)

	var games [][]int

	for i := a; i <= x; i++ {
		if i <= b {
			continue
		}
		for j := b; j <= y; j++ {
			if i > j {
				games = append(games, []int{i, j})
			}
		}
	}

	fmt.Println(len(games))
	for _, pair := range games {
		fmt.Println(fmt.Sprintf("%d %d", pair[0], pair[1]))
	}
}

