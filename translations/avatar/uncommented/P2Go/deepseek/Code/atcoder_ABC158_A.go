package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	if contains(input, "A") && contains(input, "B") {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func contains(s, substr string) bool {
	for i := 0; i < len(s); i++ {
		if s[i] == substr[0] {
			if s[i:] == substr {
				return true
			}
		}
	}
	return false
}
