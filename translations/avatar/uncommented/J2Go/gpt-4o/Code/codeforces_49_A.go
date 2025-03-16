package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s)
	length := len(s)
	var ch rune

	for i := length - 1; i >= 0; i-- {
		if s[i] != ' ' && s[i] != '?' {
			ch = rune(s[i])
			break
		}
	}

	ch = rune(strings.ToLower(string(ch)))
	if ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
