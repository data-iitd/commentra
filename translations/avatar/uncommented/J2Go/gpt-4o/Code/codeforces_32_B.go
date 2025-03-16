package main

import (
	"fmt"
)

func main() {
	var input string
	fmt.Scan(&input)
	n := []rune(input)
	s := false

	for _, char := range n {
		if char == '.' {
			if s {
				fmt.Print(1)
				s = false
			} else {
				fmt.Print(0)
			}
		} else {
			if s {
				fmt.Print(2)
				s = false
			} else {
				s = true
			}
		}
	}
}

// <END-OF-CODE>
