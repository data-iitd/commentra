package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var a string
	fmt.Scanln(&a)
	a = strings.Replace(a, ",", " ", -1)
	fmt.Println(a)
}

