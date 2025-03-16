package main

import (
	"fmt"
	"strings"
)

func main() {
	var txt string
	fmt.Scanln(&txt)

	cu := 0
	cl := 0

	for _, z := range txt {
		if z >= 'a' && z <= 'z' {
			cl++
		} else {
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

// <END-OF-CODE>
