package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a string
	a, _ = reader.ReadString('\n')
	a = strings.Replace(a, ",", " ", -1)
	fmt.Println(a)
}

