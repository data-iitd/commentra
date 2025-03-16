package main

import (
	"fmt"
	"strings"
)

func main() {
	var txt string
	fmt.Print("Enter a string: ")
	fmt.Scan(&txt)

	var cu, cl int
	for _, z := range txt {
		if z >= 'a' && z <= 'z' {
			cl++
		} else if z >= 'A' && z <= 'Z' {
			cu++
		}
	}

	var out string
	if cu > cl {
		out = strings.ToUpper(txt)
	} else {
		out = strings.ToLower(txt)
	}

	fmt.Println(out)
}

