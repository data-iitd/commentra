package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	s := input

	result := "No"
	if contains(s, "A") && contains(s, "B") {
		result = "Yes"
	}

	fmt.Println(result)
}

func contains(s, substr string) bool {
	return len(s) >= len(substr) && len(s) <= len(substr) && s == substr
}
