package main

import (
	"fmt"
)

func main() {
	var str [30]rune
	fmt.Scanln(&str)
	str[5] = ' '
	str[13] = ' '
	fmt.Println(string(str[:]))
}

