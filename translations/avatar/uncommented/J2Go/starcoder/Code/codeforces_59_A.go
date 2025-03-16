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
	text, _ := reader.ReadString('\n')
	text = strings.Replace(text, "\n", "", -1)
	uppercase := 0
	lowercase := 0
	for _, ch := range text {
		if ch >= 'A' && ch <= 'Z' {
			uppercase++
		} else if ch >= 'a' && ch <= 'z' {
			lowercase++
		}
	}
	if uppercase > lowercase {
		fmt.Println(strings.ToUpper(text))
	} else if lowercase > uppercase {
		fmt.Println(strings.ToLower(text))
	} else {
		fmt.Println(strings.ToLower(text))
	}
}

