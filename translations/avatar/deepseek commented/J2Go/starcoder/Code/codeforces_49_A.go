package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	input = strings.Replace(input, "?", "", -1)
	input = strings.ToLower(input)
	if input == "a" || input == "e" || input == "i" || input == "o" || input == "u" || input == "y" {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

