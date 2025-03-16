package main

import (
	"fmt"
	"strings"
)

func main() {
	var mes string
	fmt.Scan(&mes)
	fmt.Printf("%c%d%c\n", mes[0], len(mes)-2, mes[len(mes)-1])
}

