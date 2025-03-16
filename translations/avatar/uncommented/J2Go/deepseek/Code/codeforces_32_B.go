package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	var s bool
	for _, char := range input {
		if char == '.' {
			if s {
				fmt.Print(1)
				s = false
			} else {
				fmt.Print(0)
			}
		} else {
			if s {
				fmt.Print(2)
				s = false
			} else {
				s = true
			}
		}
	}
	fmt.Println() // Print a newline at the end
}

