package main

import (
	"fmt"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func gs() string {
	scanner.Scan()
	return scanner.Text()
}

func gi() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func gl() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func gd() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func main() {
	N := gi()
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

		sb2 := strings.Builder{}
		sb2.WriteString(sb.String())
		sb2.Reverse()
		i, _ = strconv.ParseInt(sb2.String(), 10, 64)
	}

	fmt.Println(c)
}

