package main

import (
	"fmt"
)

func generateString() []rune {
	var sb []rune
	for i := 1; i <= 1000; i++ {
		for _, digit := range fmt.Sprintf("%d", i) {
			sb = append(sb, digit)
		}
	}
	return sb
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(string(generateString()[n-1]))
}

