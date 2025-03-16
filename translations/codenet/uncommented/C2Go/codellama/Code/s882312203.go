package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	for j := 0; j < len(s); j++ {
		for i := 0; i < len(s); i++ {
			if i != j && strings.ContainsRune(s, rune(s[i])) {
				fmt.Println("no")
				return
			}
		}
	}

	fmt.Println("yes")
}

