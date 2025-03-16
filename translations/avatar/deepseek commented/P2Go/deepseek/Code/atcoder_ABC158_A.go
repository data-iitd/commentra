package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	s, _ := reader.ReadString('\n')

	if containsA, containsB := containsBoth(s, "A", "B"); containsA && containsB {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func containsBoth(s, char1, char2 string) (bool, bool) {
	return containsChar(s, char1), containsChar(s, char2)
}

func containsChar(s, char string) bool {
	return strings.Contains(s, char)
}
