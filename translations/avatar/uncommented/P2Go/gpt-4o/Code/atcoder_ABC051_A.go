package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	fmt.Println(strings.ReplaceAll(input, ",", " "))
}

// <END-OF-CODE>
