package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var scanner *Scanner
	scanner = NewScanner(os.Stdin)
	N := gi(scanner)

	i := 357
	c := 0

	for i <= N {
		s := strconv.Itoa(i)

		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
			c++
		}

		var sb strings.Builder
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
					f = true
				}
			}
		}

		if !f {
			sb.WriteByte('3')
		}

		sb2 := &strings.Builder{}
		sb2.WriteString(sb.String())
		sb2.Reset()
		for j := len(sb.String()) - 1; j >= 0; j-- {
			sb2.WriteByte(sb.String()[j])
		}

		i, _ = strconv.ParseInt(sb2.String(), 10, 64)
	}

	fmt.Println(c)
}

func gs(scanner *Scanner) string {
	return scanner.Scan()
}

func gi(scanner *Scanner) int {
	return toInt(scanner.Scan())
}

func gl(scanner *Scanner) int64 {
	return toInt64(scanner.Scan())
}

func gd(scanner *Scanner) float64 {
	return toFloat64(scanner.Scan())
}

type Scanner struct {
	bufScanner *bufio.Scanner
}

func NewScanner(reader io.Reader) *Scanner {
	bufScanner := bufio.NewScanner(reader)
	bufScanner.Split(bufio.ScanWords)
	return &Scanner{bufScanner: bufScanner}
}

func (s *Scanner) Scan() string {
	if !s.bufScanner.Scan() {
		panic("Scan failed")
	}
	return s.bufScanner.Text()
}

func toInt(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return i
}

func toInt64(s string) int64 {
	i, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func toFloat64(s string) float64 {
	f, err := strconv.ParseFloat(s, 64)
	if err != nil {
		panic(err)
	}
	return f
}
