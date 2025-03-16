package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	c := make(map[rune]int)
	for _, char := range S {
		c[char]++
	}
	Sa := make(map[rune]bool)
	for char := range c {
		Sa[char] = true
	}
	if len(Sa) != 2 {
		fmt.Println("No")
		return
	}
	for char := range Sa {
		if c[char] != 2 {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

