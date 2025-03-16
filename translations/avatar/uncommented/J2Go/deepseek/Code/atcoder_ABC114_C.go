package main

import (
	"fmt"
	"strconv"
)

func main() {
	var scanner *Scanner
	scanner = newScanner()
	N := gi(scanner)
	i := int64(357)
	c := 0
	for i <= int64(N) {
		s := strconv.FormatInt(i, 10)
		if contains3 && contains5 && contains7 {
			c++
		}
		sb := &strings.Builder{}
		f := false
		for j := 0; j < len(s); j++ {
			a := s[len(s)-1-j]
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
		sb2 := &strings.Buffer{}
		sb2.WriteString(sb.String())
		sb2.Reverse()
		i, _ = strconv.ParseInt(sb2.String(), 10, 64)
	}
	fmt.Println(c)
}

func newScanner() *Scanner {
	return &Scanner{}
}

type Scanner struct{}

func (s *Scanner) next() string {
	var input string
	fmt.Scan(&input)
	return input
}

func gi(scanner *Scanner) int {
	return parseInt(scanner.next())
}

func parseInt(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

func <END-OF-CODE>