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
	input = strings.Replace(input, " ", "", -1)
	uppercase := 0
	lowercase := 0
	for _, ch := range input {
		if ch >= 'A' && ch <= 'Z' {
			uppercase++
		} else {
			lowercase++
		}
	}
	if uppercase > lowercase {
		fmt.Println(strings.ToUpper(input))
	} else if lowercase > uppercase {
		fmt.Println(strings.ToLower(input))
	} else {
		fmt.Println(strings.ToLower(input))
	}
}

