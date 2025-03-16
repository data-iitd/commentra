package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	var a, z int
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			a = i
			break
		}
	}
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'Z' {
			z = i
			break
		}
	}
	fmt.Println(z - a + 1)
}

