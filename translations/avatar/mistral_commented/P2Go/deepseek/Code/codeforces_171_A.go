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
	parts := strings.Split(strings.TrimSpace(input), " ")

	a := parts[0]
	b := parts[1]

	maxLen := max(len(a), len(b))
	a = padZeros(a, maxLen, '0')
	b = padZeros(b, maxLen, '0')

	var s strings.Builder
	carry := 0

	for i := 0; i < maxLen; i++ {
		digitA := int(a[maxLen-i-1] - '0')
		digitB := int(b[maxLen-i-1] - '0')
		sum := digitA + digitB + carry

		if sum > 9 {
			s.WriteString(strconv.Itoa(sum)[1:])
			carry = 1
		} else {
			s.WriteString(strconv.Itoa(sum))
			carry = 0
		}
	}

	if carry == 1 {
		s.WriteString("1")
	}

	result := s.String()
	if len(result) > 0 {
		fmt.Println(result[:len(result)-1])
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func padZeros(s string, length int, char byte) string {
	for len(s) < length {
		s = string(char) + s
	}
	return s
}
