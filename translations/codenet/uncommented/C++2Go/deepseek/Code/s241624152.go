package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	var ans string
	if a == 1 || b == 1 {
		if a == 1 && b == 1 {
			ans = "Draw"
		} else if a == 1 {
			ans = "Alice"
		} else {
			ans = "Bob"
		}
	} else {
		if a == b {
			ans = "Draw"
		} else if a > b {
			ans = "Alice"
		} else {
			ans = "Bob"
		}
	}
	fmt.Println(ans)
}

