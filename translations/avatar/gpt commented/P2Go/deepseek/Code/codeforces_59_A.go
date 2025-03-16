package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	var txt string
	fmt.Scanln(&txt)

	cu := 0
	cl := 0

	for _, z := range txt {
		if unicode.IsLower(z) {
			cl++
		} else {
			cu++
		}
	}

	if cu > cl {
		fmt.Println(strings.ToUpper(txt))
	} else {
		fmt.Println(strings.ToLower(txt))
	}
}

