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
	a, b := strings.Split(input, " ")
	
	x := max(len(a), len(b))
	a = padLeft(a, x, '0')
	b = padRight(b, x, '0')
	
	s := ""
	c := 0
	for i := 0; i < x; i++ {
		d := int(b[i]) - '0' + int(a[x-i-1]) - '0' + c
		if d > 9 {
			s += strconv.Itoa(d)[1:]
			c = 1
		} else {
			s += strconv.Itoa(d)
			c = 0
		}
	}
	if c == 1 {
		s += "1"
	}
	
	result := ""
	for i := len(s) - 1; i >= 0; i-- {
		result += string(s[i])
	}
	fmt.Println(result)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func padLeft(s string, length int, char byte) string {
	if len(s) >= length {
		return s
	}
	return strings.Repeat(string(char), length-len(s)) + s
}

func padRight(s string, length int, char byte) string {
	if len(s) >= length {
		return s
	}
	return s + strings.Repeat(string(char), length-len(s))
}
