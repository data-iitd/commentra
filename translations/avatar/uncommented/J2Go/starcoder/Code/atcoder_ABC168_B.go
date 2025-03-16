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
	fmt.Println("Enter the string")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	fmt.Println("Enter the length")
	length, _ := strconv.Atoi(reader.ReadString('\n'))
	if len(input) <= length {
		fmt.Println(input)
	} else {
		fmt.Println(input[:length] + "...")
	}
}

