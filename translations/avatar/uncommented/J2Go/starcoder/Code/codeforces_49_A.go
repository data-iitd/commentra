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
	input = strings.TrimSpace(input)
	input = strings.ToLower(input)
	if strings.ContainsAny(input, "aeiouy") {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

