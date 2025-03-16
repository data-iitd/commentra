package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	for i := 0; i < len(s); i++ {
		for j := 0; j < len(s); j++ {
			if i != j && s[i] == s[j] {
				fmt.Println("no")
				return
			}
		}
	}

	fmt.Println("yes")
}

