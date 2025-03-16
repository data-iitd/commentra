package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	var a, z int

	// The first for loop iterates through the string to find the position of the first occurrence of 'A'
	for i := 0; i < len(input); i++ {
		if input[i] == 'A' {
			a = i
			break
		}
	}

	// The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
	for i := len(input) - 1; i >= 0; i-- {
		if input[i] == 'Z' {
			z = i
			break
		}
	}

	// Calculate the length of the substring between the first 'A' and the last 'Z' and print it
	fmt.Println(z - a + 1)
}

