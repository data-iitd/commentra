
package main

import "fmt"

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)
	games := make([][]int, 0)
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
	for _, v := range games {
		fmt.Println(v[0], v[1])
	}
}

