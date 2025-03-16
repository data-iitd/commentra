package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)
	games := [][]int{}
	for i := a; i <= x; i++ {
		if i <= b {
			continue
		} else {
			for j := b; j <= y; j++ {
				if i > j {
					games = append(games, []int{i, j})
				}
			}
		}
	}
	fmt.Println(len(games))
	for _, i := range games {
		fmt.Printf("%d %d\n", i[0], i[1])
	}
}

