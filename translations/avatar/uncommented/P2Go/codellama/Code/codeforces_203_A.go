package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var x, t, a, b, da, db int
	fmt.Scan(&x, &t, &a, &b, &da, &db)
	if x == 0 {
		fmt.Println("YES")
		return
	}
	a_time := min(a/da, t-1)
	b_time := min(b/db, t-1)
	for i := 0; i <= a_time; i++ {
		for j := 0; j <= b_time; j++ {
			if a-da*i == x || b-db*j == x {
				fmt.Println("YES")
				return
			}
			if (a-da*i)+(b-db*j) == x {
				fmt.Println("YES")
				return
			}
		}
	}
	fmt.Println("NO")
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 