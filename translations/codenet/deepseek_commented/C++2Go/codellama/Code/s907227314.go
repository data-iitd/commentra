package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	a, z := -1, -1

	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			a = i
			break
		}
	}

	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'Z' {
			z = i
			break
		}
	}

	fmt.Println(z - a + 1)
}

