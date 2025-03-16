
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	c := make(map[rune]int)
	for _, r := range s {
		c[r]++
	}
	sa := make(map[rune]bool)
	for _, r := range s {
		sa[r] = true
	}
	if len(sa) != 2 {
		fmt.Println("No")
		return
	}
	for r := range sa {
		if c[r] != 2 {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

