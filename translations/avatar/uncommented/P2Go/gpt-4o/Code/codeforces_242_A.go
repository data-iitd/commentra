package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)

	games := []struct{ first, second int }{}

	for i := a; i <= x; i++ {
		if i <= b {
			continue
		}
		for j := b; j <= y; j++ {
			if i > j {
				games = append(games, struct{ first, second int }{i, j})
			}
		}
	}

	fmt.Println(len(games))
	for _, game := range games {
		fmt.Printf("%d %d\n", game.first, game.second)
	}
}

// <END-OF-CODE>
