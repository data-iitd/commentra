package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")

	a := parts[0]
	b := parts[1]

	x := max(len(a), len(b))

	a = padLeft(a, x, '0')
	b = padRight(b, x, '0')

	var s strings.Builder
	c := 0

	for i := 0; i < x; i++ {
		d := int(b[i]) - '0' + int(a[x-i-1]) - '0' + c

		if d > 9 {
			s.WriteString(strconv.Itoa(d - 10))
			c = 1
		} else {
			s.WriteString(strconv.Itoa(d))
			c = 0
		}
	}

	if c == 1 {
		s.WriteString("1")
	}

	result := s.String()
	result = reverse(result)
	fmt.Println(strconv.Atoi(result))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func padLeft(s string, length int, char byte) string {
	return strings.Repeat(string(char), length-len(s)) + s
}

func padRight(s string, length int, char byte) string {
	return s + strings.Repeat(string(char), length-len(s))
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

