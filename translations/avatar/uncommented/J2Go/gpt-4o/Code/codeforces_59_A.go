package main

import (
	"fmt"
	"strings"
)

func main() {
	var word string
	fmt.Scan(&word)

	uppercase := 0
	lowercase := 0

	for _, ch := range word {
		if ch >= 'A' && ch <= 'Z' {
			uppercase++
		} else {
			lowercase++
		}
	}

	if uppercase > lowercase {
		fmt.Println(strings.ToUpper(word))
	} else {
		fmt.Println(strings.ToLower(word))
	}
}

// <END-OF-CODE>
