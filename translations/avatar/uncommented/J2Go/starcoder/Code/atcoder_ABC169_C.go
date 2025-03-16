package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a number: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	a, _ := strconv.ParseInt(input, 10, 64)
	fmt.Println("Enter a percentage: ")
	input, _ = reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	b, _ := strconv.ParseInt(input, 10, 64)
	result := (a * b) / 100
	fmt.Println(result)
}

