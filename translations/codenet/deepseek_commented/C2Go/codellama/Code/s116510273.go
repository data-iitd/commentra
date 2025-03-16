package main

import (
	"fmt"
	"strings"
)

func main() {
	var mes string
	fmt.Scan(&mes)
	length := len(mes) - 2
	fmt.Printf("%c%d%c\n", mes[0], length, mes[len(mes)-1])
}

