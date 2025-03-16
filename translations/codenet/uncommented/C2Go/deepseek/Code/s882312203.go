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
			if i != j && strings.Contains(s, string(s[j])) {
				fmt.Println("no")
				return
			}
		}
	}

	fmt.Println("yes")
}

