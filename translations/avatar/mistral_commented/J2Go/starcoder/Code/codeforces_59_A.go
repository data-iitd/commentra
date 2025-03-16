package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a word: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, "\r", "", -1)
	input = strings.ToLower(input)
	var upper, lower int
	for _, ch := range input {
		if ch >= 'A' && ch <= 'Z' {
			upper++
		} else {
			lower++
		}
	}
	if upper > lower {
		fmt.Println(strings.ToUpper(input))
	} else if lower > upper {
		fmt.Println(input)
	} else {
		fmt.Println(input)
	}
}

