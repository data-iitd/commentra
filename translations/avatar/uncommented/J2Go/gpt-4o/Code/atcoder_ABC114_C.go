package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	i := int64(357)
	c := 0

	for i <= int64(N) {
		s := strconv.FormatInt(i, 10)
		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
			c++
		}

		var sb strings.Builder
		f := false
		for j := len(s) - 1; j >= 0; j-- {
			a := s[j]
			if f {
				sb.WriteByte(a)
			} else {
				if a == '3' {
					sb.WriteByte('5')
					f = true
				} else if a == '5' {
					sb.WriteByte('7')
					f = true
				} else {
					sb.WriteByte('3')
				}
			}
		}
		if !f {
			sb.WriteByte('3')
		}
		reversed := reverseString(sb.String())
		i, _ = strconv.ParseInt(reversed, 10, 64)
	}
	fmt.Println(c)
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
