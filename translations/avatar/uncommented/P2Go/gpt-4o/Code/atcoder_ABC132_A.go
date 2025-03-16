package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)

	c := make(map[rune]int)
	for _, char := range S {
		c[char]++
	}

	Sa := make(map[rune]struct{})
	for char := range c {
		Sa[char] = struct{}{}
	}

	if len(Sa) != 2 {
		fmt.Println("No")
		return
	}

	for char := range Sa {
		if c[char] != 2 {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("Yes")
}

// <END-OF-CODE>
