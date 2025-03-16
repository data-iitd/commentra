package main

import (
	"fmt"
	"strconv"
	"strings"
)

func generateString() []rune {
	var sb strings.Builder
	for i := 1; i <= 1000; i++ {
		sb.WriteString(strconv.Itoa(i))
	}
	return []rune(sb.String())
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(string(generateString()[n-1]))
}

// <END-OF-CODE>
