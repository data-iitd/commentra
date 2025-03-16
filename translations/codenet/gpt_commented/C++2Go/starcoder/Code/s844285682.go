package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b int
	fmt.Print("Enter a time in seconds: ")
	input, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	a, _ = strconv.Atoi(strings.TrimSpace(input))
	b = a / (60 * 60)
	a = a % (60 * 60)
	b = a / 60
	a = a % 60
	fmt.Printf("%d:%d:%d\n", b, a, b)
}

