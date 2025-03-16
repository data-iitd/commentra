package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove newline character

	charCount := make(map[rune]int)
	for _, char := range input {
		charCount[char]++
	}

	allTwo := true
	for _, count := range charCount {
		if count != 2 {
			allTwo = false
			break
		}
	}

	if allTwo && len(charCount) == 2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

