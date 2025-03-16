package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	vowels := "aeiouyAEIOUY"

	for i := len(input) - 2; i >= 0; i-- {
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

func contains(s string, r byte) bool {
	for i := 0; i < len(s); i++ {
		if s[i] == r {
			return true
		}
	}
	return false
}

