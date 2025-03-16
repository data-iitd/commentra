package main

import (
	"fmt"
	"strings"
)

func main() {
	var mes string
	fmt.Scan(&mes)

	// Calculate the length of the string excluding the first and last character
	length := len(mes) - 2

	// Print the first character, the calculated length, and the last character of the string
	fmt.Printf("%c%d%c\n", mes[0], length, mes[len(mes)-1])
}

