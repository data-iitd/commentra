package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	vowels := []rune{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'}
	for i := len(input) - 1; i >= 0; i-- {
		if input[i] == ' ' || input[i] == '?' {
			continue
		} else {
			if contains(vowels, input[i]) {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
			break
		}
	}
}

func contains(slice []rune, char rune) bool {
	for _, value := range slice {
		if value == char {
			return true
		}
	}
	return false
}

