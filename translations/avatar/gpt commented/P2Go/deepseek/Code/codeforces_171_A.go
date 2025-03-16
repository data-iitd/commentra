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
	input = strings.TrimSuffix(input, "\n")
	parts := strings.Split(input, " ")
	a := parts[0]
	b := parts[1]

	maxLen := max(len(a), len(b))
	a = padLeft(a, maxLen, '0')
	b = padRight(b, maxLen, '0')

	var result strings.Builder
	carry := 0

	for i := maxLen - 1; i >= 0; i-- {
		sum := int(a[i]) - '0' + int(b[i]) - '0' + carry
		if sum > 9 {
			result.WriteString(strconv.Itoa(sum - 10))
			carry = 1
		} else {
			result.WriteString(strconv.Itoa(sum))
			carry = 0
		}
	}

	if carry == 1 {
		result.WriteString("1")
	}

	reversedResult := reverse(result.String())
	fmt.Println(reversedResult)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func padLeft(s string, length int, char byte) string {
	for len(s) < length {
		s = string(char) + s
	}
	return s
}

func padRight(s string, length int, char byte) string {
	for len(s) < length {
		s += string(char)
	}
	return s
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

