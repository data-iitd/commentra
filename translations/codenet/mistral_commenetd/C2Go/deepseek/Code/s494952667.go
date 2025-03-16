package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string

	fmt.Print("Enter a string: ")
	fmt.Scanln(&str)

	len := len(str)

	fmt.Print("Reversed string: ")

	for i := len - 1; i >= 0; i-- {
		fmt.Print(string(str[i]))
	}

	fmt.Println()
}

