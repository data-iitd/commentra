
package main

import (
	"fmt"
	"strings"
)

func main() {
	var txt string
	fmt.Print("Enter a string: ")
	fmt.Scan(&txt)
	cu := 0
	cl := 0
	for _, z := range txt {
		if z >= 'a' && z <= 'z' {
			cl++
		} else {
			cu++
		}
	}
	if cu > cl {
		out := strings.ToUpper(txt)
		fmt.Println(out)
	} else {
		out := strings.ToLower(txt)
		fmt.Println(out)
	}
}

