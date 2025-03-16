package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	output := strings.ReplaceAll(input, ",", " ")
	fmt.Println(output)
}

// <END-OF-CODE>
