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
		fmt.Println(strings.ToLower(word))
	}
}
