package main

import (
	"fmt"
	"os"
	"strconv"
)

func generateString() []rune {
	var sb []rune
	for i := 1; i <= 1000; i++ {
		sb = append(sb, rune(i))
	}
	return sb
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	fmt.Printf("%c\n", generateString()[n-1])
}

