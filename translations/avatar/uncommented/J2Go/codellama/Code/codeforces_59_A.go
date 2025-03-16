
package main

import (
	"fmt"
	"strings"
)

func main() {
	var word string
	fmt.Print("Enter a word: ")
	fmt.Scan(&word)

	var uppercase, lowercase int
	for _, ch := range word {
		if strings.ToUpper(string(ch)) == string(ch) {
			uppercase++
		} else {
			lowercase++
		}
	}

	if uppercase > lowercase {
		fmt.Println(strings.ToUpper(word))
	} else if lowercase > uppercase {
		fmt.Println(strings.ToLower(word))
	} else {
		fmt.Println(word)
	}
}

