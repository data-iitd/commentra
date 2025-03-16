package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	var a, b string
	fmt.Scan(&a, &b)

	x := max(len(a), len(b))
	a = padLeft(a, x, '0')
	b = padRight(b, x, '0')

	s := ""
	c := 0

	for i := 0; i < x; i++ {
		d := int(b[i]-'0') + int(a[x-i-1]-'0') + c
		if d > 9 {
			s += string(d%10 + '0')
			c = 1
		} else {
			s += string(d + '0')
			c = 0
		}
	}

	if c == 1 {
		s += "1"
	}

	// Reverse the string
	result := reverse(s)
	fmt.Println(result)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func padLeft(s string, length int, pad rune) string {
	return strings.Repeat(string(pad), length-len(s)) + s
}

func padRight(s string, length int, pad rune) string {
	return s + strings.Repeat(string(pad), length-len(s))
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// <END-OF-CODE>
