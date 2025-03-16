package main

import (
	"fmt"
	"strconv"
)

func generateString() []rune {
	var sb []rune
	for i := 1; i <= 1000; i++ {
		sb = append(sb, []rune(strconv.Itoa(i))...)
	}
	return sb
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(string(generateString()[n-1]))
}

// <END-OF-CODE>
