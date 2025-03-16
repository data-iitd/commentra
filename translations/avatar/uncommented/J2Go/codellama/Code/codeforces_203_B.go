package main

import (
	"fmt"
	"os"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}
	for m := 1; m <= M; m++ {
		var x, y int
		fmt.Scan(&x, &y)
		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				black[xx][yy]++
				if black[xx][yy] == 9 {
					fmt.Println(m)
					os.Exit(0)
				}
			}
		}
	}
	fmt.Println("-1")
}

