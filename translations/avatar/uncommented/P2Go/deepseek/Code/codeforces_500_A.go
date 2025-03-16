package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, t int
	fmt.Scan(&n, &t)

	var s []int
	input := ""
	for i := 0; i < n; i++ {
		fmt.Scan(&input)
		num, _ := strconv.Atoi(input)
		s = append(s, num)
	}

	current_cell := 0
	for current_cell <= t {
		current_cell += s[current_cell-1]
		if current_cell == t {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}

