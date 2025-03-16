
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var x, y, a, b int
	var games [][2]int
	fmt.Scanf("%d %d %d %d", &x, &y, &a, &b)
	for i := a; i <= x; i++ {
		if i <= b {
			continue
		}
		for j := b; j <= y; j++ {
			if i > j {
				games = append(games, [2]int{i, j})
			}
		}
	}
	fmt.Println(len(games))
	for _, v := range games {
		fmt.Printf("%d %d\n", v[0], v[1])
	}
}

