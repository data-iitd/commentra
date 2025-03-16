package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string
	fmt.Scanln(&str)

	len := len(str)

	// Reverse the string and print it
	for i := len - 1; i >= 0; i-- {
		fmt.Printf("%c", str[i])
	}
	fmt.Println()
}

