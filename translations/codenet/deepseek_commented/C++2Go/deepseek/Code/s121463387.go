package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		x := i
		s := strconv.Itoa(x)

		if x%3 == 0 || s[len(s)-1] == '3' {
			fmt.Printf(" %d", i)
			continue
		}

		for k := 0; k < len(s); k++ {
			if s[k] == '3' {
				fmt.Printf(" %d", i)
				break
			}
		}
	}

	fmt.Println()
}

