package main

import (
	"fmt"
	"strings"
)

func main() {
	var txt string
	fmt.Scan(&txt)
	cu := 0
	cl := 0
	for _, z := range txt {
		if strings.ToLower(string(z)) == string(z) {
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

