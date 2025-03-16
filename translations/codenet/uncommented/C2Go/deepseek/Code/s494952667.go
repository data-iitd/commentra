package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string
	fmt.Scanln(&str)

	len := len(str)

	for i := len - 1; i >= 0; i-- {
		fmt.Printf("%c", str[i])
	}
	fmt.Println()
}

