package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	var a, z int

	for i := 0; i < len(input); i++ {
		if input[i] == 'A' {
			a = i
			break
		}
	}

	for i := len(input) - 1; i >= 0; i-- {
		if input[i] == 'Z' {
			z = i
			break
		}
	}

	fmt.Println(z - a + 1)
}

